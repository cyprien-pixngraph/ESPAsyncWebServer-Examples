# ESPAsyncWebServer-Examples
Step by step examples for understanding ESPAsyncWebServer for esp8266 or esp32 boards

## 1-SimpleWebserver

This first sample come from https://techtutorialsx.com/2017/12/01/esp32-arduino-asynchronous-http-webserver/
  * Modify ssid and password
  * Install library if needed
  * Upload the code via Serial port
  * Monitor the serial to find the ip adress of your board
  * With a browser go to : http://ip-adress/hello
  
## 2-mdns

 _This is just to make things easier and not for ESPAsyncWebServer espacially_
 Adding mDNS capabilities.
 With this, you can access your board without knowing your ip adress
 * Change the hostname (not necessary)
 * With a browser go to : http://esp.local/hello (instead of http://ip-adress/hello)
