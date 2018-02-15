#ifndef EEPROM_UTILS
#define EEPROM_UTILS


short int writeCharToEEPROM(short int addr, char character)
{
  EEPROM.write(addr,character);
  EEPROM.commit();
  
  return addr+1;
}

short int readCharFromEEPROM(short int addr, char &character)
{
  character = EEPROM.read(addr);
  
  return addr+1;
}

short int writeStringToEEPROM(short int addr, String str)
{
  for (int i=addr; i<addr+str.length(); i++)
  {
    EEPROM.write(i, str.charAt(i-addr));
  }
  EEPROM.write(addr+str.length(), '\0');
  EEPROM.commit();

  return addr+str.length()+1;
}

short int readStringFromEEPROM(short int addr, String &str)
{
  str="";
  int i=addr;
  
  for (; ; i++)
  {
    char entry = EEPROM.read(i);
    
    if(entry == '\0') break;
    str += entry;  
  }
  return i+1;
}

void saveResetByteToEEPROM(char reset_byte)
{
  writeCharToEEPROM(0, reset_byte);
}

void readResetByteFromEEPROM(char &reset_byte)
{
  readCharFromEEPROM(0,reset_byte);
}
 
void saveSettingsToEEPROM(wifi_obj wifi_info, motor_obj motor_info)
{
  int addr = sizeof(char);

  addr = writeStringToEEPROM(addr, wifi_info.wifi_ssid);
  addr = writeStringToEEPROM(addr, wifi_info.wifi_pw);
  addr = writeStringToEEPROM(addr, wifi_info.host_name);
  addr = writeStringToEEPROM(addr, wifi_info.host_pw);
  addr = writeStringToEEPROM(addr, wifi_info.mqtt_broker);

  addr = writeStringToEEPROM(addr, motor_info.topic);
  addr = writeStringToEEPROM(addr, motor_info.pin_endstop_LOW);
  addr = writeStringToEEPROM(addr, motor_info.pin_endstop_HIGH);
  addr = writeStringToEEPROM(addr, motor_info.range_intern);
  addr = writeStringToEEPROM(addr, motor_info.range_extern);
}

void loadSettingsFromEEPROM(wifi_obj &wifi_info, motor_obj &motor_info)
{
  int addr = sizeof(char);

  String val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.wifi_ssid=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.wifi_pw=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.host_name=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.host_pw=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.mqtt_broker=val;
  
  addr = readStringFromEEPROM(addr, val);
  motor_info.topic=val;
  addr = readStringFromEEPROM(addr, val);
  motor_info.pin_endstop_LOW=val;
  addr = readStringFromEEPROM(addr, val);
  motor_info.pin_endstop_HIGH=val;
  addr = readStringFromEEPROM(addr, val);
  motor_info.range_intern=val;
  addr = readStringFromEEPROM(addr, val);
  motor_info.range_extern=val;
}

#endif //EEPROM_UTILS




