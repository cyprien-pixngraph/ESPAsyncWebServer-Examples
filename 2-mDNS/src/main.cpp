/**
 Adding mDNS capabilities.
 With this, you can access your board without knowing your ip adress
 * Change the hostname (not necessary)
 * With a browser go to : http://esp.local/hello (instead of http://ip-adress/hello)
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h> // Add mDNS

const char* ssid = "FreeboxCR";
const char* password =  "YourNetworkName";
const char * hostName = "yourNetworkPassword"; // Name of your board (add .local to access to it)

AsyncWebServer server(80);



void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());
  // Set up mDNS responder:
  // - first argument is the domain name, in this example
  //   the fully-qualified domain name is "esp8266.local"
  // - second argument is the IP address to advertise
  //   we send our IP address on the WiFi network
  if (!MDNS.begin(hostName)) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");

  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello World");
  });

  server.begin();
}

void loop(){
}
