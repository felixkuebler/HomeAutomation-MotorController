#ifndef WIFI_UTILS
#define WIFI_UTILS

struct wifi_obj
{
  String wifi_ssid;
  String wifi_pw;
  String host_name;
  String host_pw;
  String mqtt_broker;

  wifi_obj(): wifi_ssid(""), host_name(""), host_pw(""), wifi_pw(""), mqtt_broker(""){}
  wifi_obj(String ssid): wifi_ssid(ssid), host_name(ssid), host_pw(""), wifi_pw(""), mqtt_broker(""){}
};

String wifiToString(wifi_obj wifi_info)
{
  String str;
  str+= "wifi ssid : " + wifi_info.wifi_ssid + "\n";
  str+= "wifi pw : " + wifi_info.wifi_pw + "\n";
  str+= "host name : " + wifi_info.host_name + "\n";
  str+= "host pw : " + wifi_info.host_pw + "\n";
  str+= "mqtt broker : " + wifi_info.mqtt_broker + "\n";
  return str;
}

IPAddress stringToIP(String str)
{
  String sub_strings[4];
  for(int i,j,l=0; i<str.length() && l<4; i++)
  {
    if(str.charAt(i)=='.')
    {
      sub_strings[l++] = str.substring(j,i);
      j=i+1;
    }
  }
  IPAddress ip(sub_strings[0].toInt(), sub_strings[1].toInt(), sub_strings[2].toInt(), sub_strings[3].toInt());
  return ip;
}

String ipToString(IPAddress ip)
{
  return String(ip[0]) + "." + String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
}

bool networkAvailable(String network)
{
  int wifiCount = WiFi.scanNetworks();
  for(int i=0; i< wifiCount; i++)
  {
    if(WiFi.SSID(i) == network) return true;  
  }

  return false;
}



#endif //WIFI_UTILS




