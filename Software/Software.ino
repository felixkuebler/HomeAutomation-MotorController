
#include <map>
#include <vector>

#include <ESP8266WiFi.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h> 
#include <PubSubClient.h>
#include <ESP8266HTTPUpdateServer.h>
#include <EEPROM.h>

#include "utils.h"
#include "motor_utils.h"
#include "wifi_utils.h"
#include "eeprom_utils.h"
#include "web_interface.h"


wifi_obj wifi_info;
motor_obj motor_info;

short int reset_pin;


DNSServer dnsServer;
ESP8266WebServer wifiServer(80);
WiFiClient wifiClient;
ESP8266HTTPUpdateServer wifiUpdater;
PubSubClient client(wifiClient);


CONFIG setup_type = default_config;
bool network_available = false;



/*
 * this function is called when a html request was send to the local html server
 */
void htmlHandleRequest() 
{
  //request counter
  short int request_count = 0;
  
  //get ssid request message from client
  String val = wifiServer.arg("wifi_ssid");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("wifi_ssid : " + val);
    wifi_info.wifi_ssid = val;
    request_count++;
  }

  //get pw request message from client
  val = wifiServer.arg("wifi_pw");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("wifi_pw : " + val);
    wifi_info.wifi_pw = val;
    request_count++;
  }

  //get host name request message from client
  val = wifiServer.arg("host_name");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("host name : " + val);
    wifi_info.host_name = val;
    request_count++;
  }

  //get host name request message from client
  val = wifiServer.arg("host_pw");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("host pw : " + val);
    wifi_info.host_pw = val;
    request_count++;
  }
  
  //get mqtt broker request message from client
  val = wifiServer.arg("mqtt_broker");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("mqtt broker : " + val);
    wifi_info.mqtt_broker = val;
    request_count++;
  }

  //get motor topic request message from client
  val = wifiServer.arg("motor_topic");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("motor_topic : " + val);
    motor_info.topic = val;
    request_count++;
  }

  //get motor range_extern request message from client
  val = wifiServer.arg("motor_range_extern");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("motor_range_extern : " + val);
    motor_info.range_extern = val;
    request_count++;
  }

  //get motor calibration command request message from client
  val = wifiServer.arg("motor_calibration");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    Serial.println("motor calibration triggered");
    calibrateMotor(motor_info);
    request_count++;
  }

  //get reset trigger from client
  String reset_settings = wifiServer.arg("reset_settings");
  //check if a reset was triggered
  if(reset_settings.length()>0)
  {
    Serial.println("System Settings set to default");
    //write reset flag to eeprom to use after a system reboot
    writeCharToEEPROM(0, 0);

    //reboot system
    ESP.eraseConfig();
    ESP.reset();
  }

  //get save trigger from client
  String save_settings = wifiServer.arg("save_settings");
  //check if reboot was triggered
  if(save_settings.length()>0)
  {
    Serial.println("user settings saved, system is going to restart");

    //save local changes to eeprom
    saveSettingsToEEPROM(wifi_info, motor_info);
    writeCharToEEPROM(0, 1);
    
    //reboot system
    ESP.eraseConfig();
    ESP.reset();
  }

  //give wifiServer new webpage
  wifiServer.send(200, "text/html", generateWebpage(wifi_info, motor_info));
}


/*
 * this function is called when a mqtt post was received
 */
void mqttSubscribeCallback(char* topic, byte* payload, unsigned int length) 
{  

  //turn byte* into String
  String msg ="";
  for(int i=0; i<length; i++)
  {
    msg+=(char)payload[i];
  }

  Serial.print("mqtt post \"");
  Serial.print(msg);
  Serial.print("\" on topic \"");
  Serial.print(topic);
  Serial.println("\" received");
  
  short int val = msg.toInt();
  
  if (val>=0 && val<=motor_info.range_extern.toInt())
  {
    //TODO
    long increment = motor_info.range_intern.toInt() / motor_info.range_extern.toInt();
    long new_state = increment*val;
    long old_state = motor_info.state;
    long diff = new_state-old_state;

    short int dir = HIGH;
    short int sign = 1;
    if (diff < 0)
    {
      dir = !dir;
      diff*=-1;
      sign = -1;
    }  

    digitalWrite(motor_info.pin_dir, dir);
    digitalWrite(motor_info.pin_enable, LOW);

    double current = analogRead(motor_info.pin_current);
    long steps = 0;
    for ( ; steps < diff; steps++)
    {
      digitalWrite(motor_info.pin_step, !digitalRead(motor_info.pin_step));
      delay(0);
    
      if( isStallDetected(motor_info.pin_current, current))
      {    
        Serial.println("Stall Detected!");
        break;
      }
    }
    motor_info.state =  motor_info.state + (sign*steps);
    
    digitalWrite(motor_info.pin_enable, HIGH);

  }
  else
  {
    Serial.print("received value is out of range_extern");  
  }
  delay(10);
}

/*
 * this function is called a interrupt was triggerd on an input pin
 */
void mqttPublishCallback() 
{  
  //client.publish((it->second.topic).c_str(), (it->second.on_command).c_str());
}

/*
 * this function tryes to reconnect the mqtt client to the mqtt broker
 */
void mqttReconnect() 
{
  //repeat until a connection is astablished
  if (!client.connected()) 
  {
    Serial.print("attempting mqtt connection to ");
    Serial.print(wifi_info.mqtt_broker);
    Serial.print(" as ");
    Serial.print(wifi_info.host_name);
    Serial.print("...");
    
    // attempt to connect
    if (client.connect(wifi_info.host_name.c_str()))
    {
      Serial.println("  ok");

      //add motor to mqtt subscriber list
      client.subscribe((motor_info.topic).c_str());
    } 
    else 
    {
      //print error value
      Serial.print("  fail, rc=");
      Serial.println(client.state());
    }
  }
}


/*
 * this function will setup all wifi functions
 */
void wifi_setup(char reset_byte)
{
  //check reset indicatior
  if(reset_byte==0)
  {
    //reset was applied
    Serial.println("0  -> reset to default config");
    
    //save default settings to eeprom
    Serial.println("save default settings to epprom");
    Serial.print(wifiToString(wifi_info));
    Serial.print(motorToString(motor_info));
    saveSettingsToEEPROM(wifi_info, motor_info);

    //start access point for settings configuration 
    Serial.println("start access point");
    WiFi.softAPdisconnect(true);
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    delay(100);
    WiFi.hostname(wifi_info.host_name);
    WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
    WiFi.softAP(wifi_info.host_name.c_str());

    Serial.println("start dns captive portal");
    dnsServer.start(53, "*", IPAddress(192, 168, 1, 1));

    setup_type = default_config;
  }
  else
  {
    //reset was not applied
    Serial.println("1  -> load user config");

    //load settings from eeprom, make backup of wifi_info
    Serial.println("load settings from epprom");
    wifi_obj wifi_info_backup = wifi_info;
    loadSettingsFromEEPROM(wifi_info, motor_info);
    Serial.print(wifiToString(wifi_info));
    Serial.print(motorToString(motor_info));
    
    //connect to wifi network
    Serial.println("start as wifi client station");
    WiFi.softAPdisconnect(true);
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    delay(100);
    WiFi.hostname(wifi_info.host_name);

    if(wifi_info.wifi_pw.length()>0)
    {
      WiFi.begin(wifi_info.wifi_ssid.c_str(), wifi_info.wifi_pw.c_str());
    }
    else
    {
      WiFi.begin(wifi_info.wifi_ssid.c_str());
    }

    //wait for wifinetwork, timeout after 20 seconds
    Serial.print("connecting to ");
    Serial.print(wifi_info.wifi_ssid);
    Serial.print("...");
    bool timeout = false;
    for(int timer = 0; WiFi.status() != WL_CONNECTED; timer++)
    {
      delay(500);
      Serial.print(".");

      if(timer>=40)
      {
        timeout = true;
        break;
      }
    }

    //check if timeout occured
    if(timeout)
    {
      //timeout was triggered
      Serial.println(" fail");
      
      //start access point if connection to network not possible
      Serial.println("start as accesspoint");
      WiFi.softAPdisconnect(true);
      WiFi.disconnect();
      WiFi.mode(WIFI_AP);
      delay(100);
      WiFi.hostname(wifi_info.host_name);
      WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));

      if(wifi_info.host_pw.length()>0)
      {
        WiFi.softAP(wifi_info.host_name.c_str(), wifi_info.host_pw.c_str());
      }
      else
      {
        WiFi.softAP(wifi_info.host_name.c_str());
      }

      Serial.println("start dns captive portal");
      dnsServer.start(53, "*", IPAddress(192, 168, 1, 1));

      setup_type=backup_config;

      network_available = networkAvailable(wifi_info.wifi_ssid);

    }
    else 
    {
      //no timeout
      Serial.println(" ok");

      //start mqtt client
      Serial.println("start mqtt pub/sub client");
      client.setServer(wifi_info.mqtt_broker.c_str(), 1883);
      client.setCallback(mqttSubscribeCallback);

      setup_type = user_config;
    }
  }
    
  //define request actions
  wifiServer.onNotFound(htmlHandleRequest);

  //start http server
  Serial.println("start http server");
  wifiUpdater.setup(&wifiServer);
  wifiServer.begin();
}


/*
 * on system boot this function is called once for setup purposes
 */
void setup(void)
{
  //start serial connection
  Serial.begin(9600);

  //add default wifi info
  wifi_info = wifi_obj("HA_Node_005");

  //add default motor info
  motor_info = motor_obj("motor_1", 14, 13, 12, A0);
  reset_pin = 4;

  //define eeprom space
  EEPROM.begin(512);

  //read first byte of eeprom as reset indicatior
  Serial.print("read reset byte from eeprom: ");
  char reset_byte;
  readCharFromEEPROM(0, reset_byte);
  
  wifi_setup(reset_byte);
}


/*
 * main loop that evaluates dns, wifiServer and mqtt events
 */
void loop(void)
{
  //check if a connection to network was established
  if(setup_type==user_config)
  {
    //try to connect to mqtt broker
    mqttReconnect();

    //if connection lost reboot
    if(WiFi.status() != WL_CONNECTED)
    {
      WiFi.softAPdisconnect(true);
      WiFi.disconnect();
      delay(100);
      wifi_setup(1);
      
      //reboot system
      //ESP.eraseConfig();
      //ESP.reset();
    }
  }
  else if(setup_type==backup_config)
  {
    //check if a network exists that matches the users network that did not exist before
    if(!network_available)
    {
      if(networkAvailable(wifi_info.wifi_ssid))
      {
        WiFi.softAPdisconnect(true);
        WiFi.disconnect();
        delay(100);
        wifi_setup(1);
      
        //reboot system
        //ESP.eraseConfig();
        //ESP.reset();
      }
    }
  }

  //repeat following commands 100 times before next mqtt reconnect attempt
  for (short int timeout = 0; timeout < 100; timeout++)
  { 
    //check if a connection to network was established
    if(setup_type==user_config)
    {
      //handle mqtt client
      client.loop();
      mqttPublishCallback();
    }

    dnsServer.processNextRequest();
    wifiServer.handleClient();

    delay(50);
  }

  //check for hardware reset
  if(digitalRead(reset_pin)==HIGH)
  {
    /*
    Serial.print("reset button high");
    writeCharToEEPROM(0, 0);
    ESP.eraseConfig();
    ESP.reset();
    */
  }
}



