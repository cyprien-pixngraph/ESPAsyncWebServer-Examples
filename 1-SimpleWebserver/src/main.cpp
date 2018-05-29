/**
 This first sample come from https://techtutorialsx.com/2017/12/01/esp32-arduino-asynchronous-http-webserver/
  * Modify ssid and password
  * Install library if needed
  * Upload the code via Serial port
  * Monitor the serial to find the ip adress of your board
  * With a browser go to : http://ip-adress/hello
 */

#include <Arduino.h> // Only for PlatformIO
#include <ESP8266WiFi.h> // Configure WIFI
#include <FS.h> // File system, not used here but needed by the othe libraries
#include <ESPAsyncTCP.h> // Lower level librabry
#include <ESPAsyncWebServer.h>

const char* ssid = "FreeboxCR"; // Change it !!
const char* password =  "suzieetnoemie"; // Change it !!

AsyncWebServer server(80); // server variable

void setup(){
  Serial.begin(115200); // for debugging

  WiFi.begin(ssid, password); // Start the network

  while (WiFi.status() != WL_CONNECTED) { // Try to connect
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP()); // Connected ! Show the IP

  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){ // define a new route /hello
    request->send(200, "text/plain", "Hello World"); // return Hello World message
  });

  server.begin(); // Start the server
}

void loop(){
}
