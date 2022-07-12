#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Bme280.h>
#include "LittleFS.h"
#include "AsyncJson.h"
#include <ArduinoJson.h>

const char* ssid = "virusInfectedNetwork_2";
const char* password = "bxd1xfb4G";

AsyncWebServer server(80);
Bme280TwoWire sensor;

String getTemperature();
String getHumidity();
String getAnalogSensor(byte pin);
String addStringLine(String value, byte id, String symbol, String type, String name, bool last);

struct dataHolder {
  byte id;
  String value;
};

// just as example
dataHolder switcher = {5, "false"};

void notFound(AsyncWebServerRequest *request){
  request->send(404, "application/json", "{\"message\":\"Not found\"}");
}

void setup() {
  Serial.begin(115200);

  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  Wire.begin();
  sensor.begin(Bme280TwoWireAddress::Primary);
  sensor.setSettings(Bme280Settings::defaults());

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html");
  });

  server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/favicon.ico");
  });

  server.on("/static/js/main.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/static/js/main.js");
  });

  server.on("/static/css/main.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/static/css/main.css");
  });

  server.on("/getAllData", HTTP_GET, [](AsyncWebServerRequest *request){
    String toSend = "[ " + addStringLine(getTemperature(), 3, "C", "sensor", "Temperature", false);
    toSend += addStringLine(getHumidity(), 4, "%", "sensor", "Air Humidity", false);
    toSend += addStringLine(getAnalogSensor(32), 1, " points", "sensor", "Plant 1", false);
    toSend += addStringLine(getAnalogSensor(33), 2, " points", "sensor", "Plant 2", true);
    toSend += " ]";
    request->send(200, "text/plain", toSend);
  });

  // /getData?id=xx
  server.on("/getData", HTTP_GET, [](AsyncWebServerRequest *request){
    String componentID;
    if(request->hasParam("id")) {
      componentID = request->getParam("id")->value();
    }
    String toSend;
    if(componentID == "1") {
      toSend = addStringLine(getAnalogSensor(32), 1, " points", "sensor", "Plant 1", true);
    }
    if(componentID == "2") {
      toSend = addStringLine(getAnalogSensor(33), 2, " points", "sensor", "Plant 2", true);
    }
    if(componentID == "3") {
      toSend = addStringLine(getTemperature(), 3, "C", "sensor", "Temperature", true);
    }
    if(componentID == "4") {
      toSend = addStringLine(getHumidity(), 4, "%", "sensor", "Air Humidity", true);
    }
    request->send(200, "text/plain", toSend);
  });

  AsyncCallbackJsonWebHandler* sliderHandler = new AsyncCallbackJsonWebHandler("/update/slider", [](AsyncWebServerRequest *request, JsonVariant &json) {
    StaticJsonDocument<100> data;
    char* response;
    // if (json.is<JsonArray>())
    // {
    //   data = json.as<JsonArray>();
    // }
    // else if (json.is<JsonObject>())
    // {
    //   data = json.as<JsonObject>();
    // }
    data = json.as<JsonObject>();
    DeserializationError error = deserializeJson(data, response);
    const char* id = data["id"];
    const char* value = data["value"];

    Serial.print("Id is ");
    Serial.println(id);
    Serial.print("Value is ");
    Serial.println(value);
    
    request->send(200, "application/json", response);
  });

  server.addHandler(sliderHandler);

  server.onNotFound(notFound);

  server.begin();
}

void loop() {
}

String getTemperature() {
  String temp = String(sensor.getTemperature());
  return temp;
}

String getHumidity() {
  String hum = String(sensor.getHumidity());
  return hum;
}

String getAnalogSensor(byte pin) {
  return String(analogRead(pin));
}

// create JSON element
String addStringLine(String value, byte id, String symbol, String type, String name, bool last) {
  String lastComma = ", ";
  if (last) lastComma = " ";
  String line = "{\"id\": \"" 
    + String(id) + "\", \"type\": \"" 
    + type + "\", \"name\": \"" 
    + name + "\", \"value\": \"" 
    + value + "" 
    + symbol + "\"}" + lastComma;
    return line;
}