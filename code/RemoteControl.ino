#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>

const char* ssid = "Remote Control";

AsyncWebServer server(80);

String header;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  
  WiFi.softAP(ssid);

  SPIFFS.begin();

  MDNS.begin("remote");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/intro.html");
  });

  
  server.on("/wifi", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/intro.html");
    String wifi_ssid_string = request->getParam("ssid")->value();
    char wifi_ssid[32];
    wifi_ssid_string.toCharArray(wifi_ssid, 32);
    String wifi_pass_string = request->getParam("pass")->value();
    char wifi_pass[63];
    wifi_pass_string.toCharArray(wifi_pass, 63);
    Serial.println(wifi_ssid);
    Serial.println(wifi_pass);
    WiFi.softAPdisconnect(true);
    WiFi.begin(wifi_ssid, wifi_pass);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi..");
    }
  });
  
  server.begin();
}

void loop() {
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}
