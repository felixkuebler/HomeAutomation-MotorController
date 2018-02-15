#ifndef WEB_INTERFACE
#define WEB_INTERFACE


String generateHeader(wifi_obj wifi_info)
{
  String page="";

  page += "<header>" + wifi_info.host_name +" Settings</header>";

  return page;
}

String generateGeneralSettings(wifi_obj wifi_info)
{
  String page = "";
  
  page +="<div id=\"general\">";
    page +="<h1>General Settings</h1>";
    page +="<br>";
    page +="<div>";
      page +="Device Name ";
      page +="<input class=\"text-input\" type=\"text\" id=\"host_name\" value=\"" + wifi_info.host_name + "\">";
    page +="</div>";
    page +="<br>";
    page +="<div>";
      page +="Device Password ";
      page +="<input class=\"text-input\" type=\"text\" id=\"host_pw\" value=\"" + wifi_info.host_pw + "\">";
    page +="</div>";
    page +="<br>";
    page +="<div class=\"info\">Choose a device name to access this website from your local network (http://device-name/). If the device is not able to connect to the network a wifi hotspot with an identical name will be generated.</div>";
  page +="</div>";

  return page;
}

String generateWifiSettings(wifi_obj wifi_info)
{
  String page ="";

  page += "<div class=\"hidden\" id=\"wifi\">";
    page += "<h1>WiFi Settings</h1>";
    page += "<br>";
    page += "<div>";
      page += "Network Name "; 
      page += "<select class=\"select-input\" id=\"wifi_ssid\">";
        page += "<option value=\"" + wifi_info.wifi_ssid + "\">" + wifi_info.wifi_ssid + "</option>";

        int wifiCount = WiFi.scanNetworks();
        for(int i=0; i< wifiCount; i++)
        {
          page += "<option value=\"" + WiFi.SSID(i) + "\">" + WiFi.SSID(i) + "</option>";
        }
      page += "</select>"; 
    page += "</div>";
    page += "<br>";
    page += "<div>";
      page += "Network Password ";
      page += "<input class=\"text-input\" type=\"text\" id=\"wifi_pw\" value=\"" + wifi_info.wifi_pw + "\">";
    page += "</div>";
    page += "<br>";
    page += "<div class=\"info\">Select a Network for this device to connect to. The selected Network must be password protected!</div>";
  page += "</div>";
  
  return page;
}


String generateMQTTSettings(wifi_obj wifi_info, motor_obj motor_info)
{
  String page = "";
  
  page += "<div class=\"hidden\" id=\"mqtt\">";
    page += "<h1>MQTT Settings</h1>";
    page += "<br>";
    page += "<div>";
      page += "Broker IP ";
      page += "<input class=\"text-input\" type=\"text\" id=\"mqtt_broker\" value=\"" + wifi_info.mqtt_broker + "\">";
    page += "</div>";
    page += "<br>";
    page +="<div class=\"info\">Enter the local IP of your MQTT broker (e.g. Mosquitto on a Raspbarry Pi).</div>";
    page += "<br>";
    page += "<div>";
      page += "<br>";        
      page += "<div>";
        page += "Motor Topic ";
        page += "<input class=\"text-input\" type=\"text\" id=\"motor_topic\" value=\"" + motor_info.topic + "\">";
      page += "</div>";
      page += "<br>";
      page += "<div>";
        page += "Motor Range ";
        page += "<input class=\"text-input\" type=\"text\" id=\"motor_range_extern\" value=\"" + motor_info.range_extern + "\">";
      page += "</div>";
      page += "<br>";
      page += "<div>";
        page += "<button class=\"btn btn-commands\" onclick=\"calibrateMotor()\">Motor Calibration</button>";      
      page += "</div>";
    page += "</div>";  
  page += "</div>";

  return page;
}

String generateOpenhabScript()
{
  String switch_id;
  String switch_name;

  String switch_mqtt_topic;

  String switch_command_on;
  String switch_command_off;
  String switch_command_toggle;

  String for_sitemap = "";
  for_sitemap += "Switch item=" + switch_id;

  String for_items = "";
  for_items += "Switch " + switch_id + "\"" + switch_name + "\"";
  for_items += "{mqtt=\"";
  for_items += ">[broker:" + switch_mqtt_topic + ":command:ON:" + switch_command_on + "],";
  for_items += ">[broker:" + switch_mqtt_topic + ":command:OFF:" + switch_command_off + "]";
  for_items += "\"}\n";
  for_items += "String mqttMessage_" + switch_id + " {mqtt=\"<[broker:" + switch_mqtt_topic + ":state:default]\"}";

  String for_rules = "";
  for_rules += "rule \"mqttMessage_" + switch_id + "_changed\n";
  for_rules += "when\n";
  for_rules += "\tItem mqttMessage_" + switch_id + " changed\n";
  for_rules += "then\n";
  for_rules += "\tif(mqttMessage_" + switch_id + ".state.toString.contains(\"" + switch_command_off + "\"))\n";
  for_rules += "\t{\n";
  for_rules += "\t\t" + switch_id + ".postUpdate(OFF)\n";
  for_rules += "\t}\n";
  for_rules += "\telse if(mqttMessage_" + switch_id + ".state.toString.contains(\"" + switch_command_on + "\"))\n";
  for_rules += "\t{\n";
  for_rules += "\t\t" + switch_id + ".postUpdate(ON)\n";
  for_rules += "\t}\n";
  for_rules += "\telse if(mqttMessage_" + switch_id + ".state.toString.contains(\"" + switch_command_toggle + "\"))\n";
  for_rules += "\t{\n";
  for_rules += "\t\t" + switch_id + ".postUpdate(if(" + switch_id + ".state == ON) OFF else ON)\n";
  for_rules += "\t\tmqttMessage_" + switch_id + ".postUpdate(\"\")\n";
  for_rules += "\t}\n";
  for_rules += "end";

  return "";
}

String generateScript()
{
  String script ="";
  
  script += "<script>";
    script += "function handleSettings(element){"; 
      script += "var setting_buttons= document.getElementsByClassName(\"btn-settings\");";
      script += "for (var i = 0; i < setting_buttons.length; ++i){";
        script += "var setting_button = setting_buttons[i]; ";
        script += "var setting_frame= document.getElementById(setting_button.getAttribute(\"for\"));";
        script += "setting_button.style.borderWidth= \"1px\";";
        script += "setting_button.style.background = \"rgba(120,120,120,0.95)\";";
        script += "setting_button.classList.remove(\"dontHover\");";
        script += "setting_frame.style.display = \"none\";";
      script += "}";
      script += "var setting_frame = document.getElementById(element.getAttribute(\"for\")); ";
      script += "setting_frame.style.display = \"block\";";
      script += "element.style.borderWidth = \"0\";";
      script += "element.style.background = \"rgba(180,180,180,0.95)\";";
      script += "element.classList.add(\"dontHover\");";
    script += "}";

     script += "function handleOptions(element){"; 
      script += "var setting_buttons= document.getElementsByClassName(\"btn-options\");";
      script += "for (var i = 0; i < setting_buttons.length; ++i){";
        script += "var setting_button = setting_buttons[i]; ";
        script += "var setting_frame= document.getElementById(setting_button.getAttribute(\"for\"));";
        script += "setting_button.style.background = \"rgba(120,120,120,0.95)\";";
        script += "setting_button.classList.remove(\"dontHover\");";
        script += "setting_frame.style.display = \"none\";";
      script += "}";
      script += "var setting_frame = document.getElementById(element.getAttribute(\"for\")); ";
      script += "setting_frame.style.display = \"block\";";
      script += "element.style.background = \"rgba(180,180,180,0.95)\";";
      script += "element.classList.add(\"dontHover\");";
    script += "}";

    script += "function sendSettings(){";
      script += "var msg = \"?\";";
      script += "var selects = document.getElementsByTagName(\"select\");";
      script += "for (var i = 0; i < selects.length; ++i){";
        script += "var id = selects[i].getAttribute(\"id\");";
        script += "var value = selects[i].value;";
        script += "msg+= id + \"=\" + value + \"&\";";
      script += "}";
      script += "var inputs = document.getElementsByTagName(\"input\");";
      script += "for (var i = 0; i < inputs.length; ++i){";
        script += "var id = inputs[i].getAttribute(\"id\");";
        script += "var value = inputs[i].value;";
        script += "msg+= id + \"=\" + value + \"&\";";
      script += "}";
      script += "msg+= \"save_settings=true\";";
      script += "if(confirm(\"The system is going to reboot after the settings are saved. Do You want to continue?\"))";
      script += "{";
        script += "var xhttp = new XMLHttpRequest();";
        script += "xhttp.onreadystatechange = function(){";
          script += "if (this.readyState == 4 && this.status == 200){}";
        script += "};";
        script += "xhttp.open(\"GET\", msg, true);";
        script += "xhttp.send();";
      script += "}";
    script += "}";

    script += "function calibrateMotor(){";
      script += "var xhttp = new XMLHttpRequest();";
      script += "xhttp.onreadystatechange = function(){";
        script += "if (this.readyState == 4 && this.status == 200){}";
      script += "};";
      script += "xhttp.open(\"GET\", \"?motor_calibration=true\", true);";
      script += "xhttp.send();";
    script += "}";
    
    script += "function sendReset(){";
      script += "if(confirm(\"The system is going to roboot after settings are reset to default. Do You want to continue?\"))";
      script += "{";
        script += "var xhttp = new XMLHttpRequest();";
        script += "xhttp.onreadystatechange = function(){";
          script += "if (this.readyState == 4 && this.status == 200){}";
        script += "};";
        script += "xhttp.open(\"GET\", \"?reset_settings=true\", true);";
        script += "xhttp.send();";
      script += "}";
    script += "}";

  script += "</script>";

  return script;
}

String generateCSS()
{
  String css = "";
  
  css += "<style>";
    css += "header {width:100vw; height:25vh; margin:0; padding:0; text-align:center; display: table-cell; vertical-align:middle; font-family:Verdana; font-weight:100; font-size:11vh; background:rgba(180,180,180,0.7)}";
    css += "h1 {margin:0; padding:0; font-family:Verdana; font-weight:100; font-size:6vh}";
    css += "button:focus {outline:0}";
    css += ".main-frame {width:100vw; height:75vh; margin:0; padding:0; overflow:hidden}";
    css += ".left-frame {width:20vw; height:75vh; float:left; margin:0; padding:0; text-align:center; position:relative; font-family:Verdana; font-weight:100; font-size:4vh}";
    css += ".right-frame {width:80vw; height:75vh; float:right; margin:0; padding:0; text-align:center; position:relative; font-family:Verdana; font-weight:100; font-size:3vh; background:rgba(180,180,180,0.95)}";
    css += ".scrollable {overflow:scroll; width:80vw; height:55vh; position:absolute; bottom:0}";
    css += ".spaceholder {width:20vw; height:31.1vh; margin:0; margin-top:30vh; padding:0; text-align:center; font-family:Verdana; font-weight:100; font-size:3vh; background:rgba(120,120,120,0.95)}";
    css += ".info {width:40vw; margin-left: 20vw; font-family:Verdana; font-weight:100; font-size:1.8vh}";
    css += ".hidden {display:none}";
    css += ".btn {background:rgba(120,120,120,0.95); width:20vw; border:none; text-align:center; text-decoration:none; cursor:pointer; margin:0; padding:0; font-family:Verdana; font-weight:100; border-style: solid; border-color:rgba(110,110,110,0.95); border-width:1px;}";
    css += ".btn:not(.dontHover):hover {background:rgba(100,100,100,0.95) !important}";
    css += ".selected {background:rgba(180,180,180,0.95); border-width:1;}";
    css += ".selected-noborder {background:rgba(180,180,180,0.95); border-width:0;}";
    css += ".btn-settings {height:10vh; font-size:3vh}";
    css += ".btn-requests {height:7vh; font-size:2vh}";
    css += ".settings {position:absolute; top:0}";
    css += ".requests {position:absolute; bottom:0}";
    css += ".btn-options {max-width:10vw; height:4vh; font-size:2vh; display:inline-block}";
    css += ".btn-commands {max-width:20vw; height:4vh; font-size:2vh}";
    css += ".text-input {width:20vw; height:3vh; margin:0; padding:0; font-family:Verdana; font-weight:100; font-size:2vh}";
    css += ".select-input {width:20vw; height:4vh; margin:0; padding:0; font-family:Verdana; font-weight:100; font-size:2vh}";
    css += "body {margin:0; padding:0; overflow:hidden; background-image:url('data:image/jpeg;base64,";
    //String str ="url('data:image/jpeg;base64,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')";
    css += "'); background-size: cover; background-repeat: no-repeat;}";
  css += "</style>";

  return css;
}

String generateWebpage(wifi_obj wifi_info, motor_obj motor_info)
{
  String page = "";
  
  page += "<!DOCTYPE html>";
    page += "<body>";
 
      page += generateHeader(wifi_info);

      page += "<div class=\"main-frame\">";
        page += "<div class=\"left-frame\">";
          page += "<div class=\"settings\">";
            page += "<button class=\"btn btn-settings selected-noborder dontHover\" for=\"general\" onclick=\"handleSettings(this)\">Gerneral Settings</button>";
            page += "<button class=\"btn btn-settings\" for=\"wifi\" onclick=\"handleSettings(this)\">WiFi Settings</button>";
            page += "<button class=\"btn btn-settings\" for=\"mqtt\" onclick=\"handleSettings(this)\">MQTT Settings</button>";
          page += "</div>";
          page += "<div class=\"spaceholder\"></div>";
          page += "<div class=\"requests\">";
            page += "<button class=\"btn btn-requests\" onclick=\"sendSettings()\">Save Settings</button>";
            page += "<button class=\"btn btn-requests\" onclick=\"sendReset()\">Reset Settings</button>"; 
          page += "</div>";
        page += "</div>";
        page += "<div class=\"right-frame\">";

          page += generateGeneralSettings(wifi_info);
          page += generateWifiSettings(wifi_info);
          page += generateMQTTSettings(wifi_info, motor_info);

        page += "</div>";
      page += "</div>";

      page += generateScript();
      page += generateCSS();

    page += "</body>";
  page += "</html>";

  return page;
   
}


#endif //WEB_INTERFACE

 



