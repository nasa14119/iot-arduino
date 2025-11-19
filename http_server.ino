#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include "WebServer.h"
#include "ArduinoJson.h"
#include "water_service.ino"
template<typename T, typename M>
auto wrapper(T* instance, M method) {
  return [instance, method]() {
    (instance->*method)();
  };
}
const int PORT = 80; 
std::pair<float, float> get_amb(); 
class HTTPServer {
  WebServer server;
  WaterService water_service;   
public: 
  HTTPServer(): server(PORT), water_service(){}
  // Handlers 
  void handleStatus(){
    JsonDocument res;
    // Get sensor data
    auto [temp, hum] = get_amb(); 
    res["temperature"] = temp; 
    res["humidity"] = hum;
    res.shrinkToFit(); 
    server.send(200, "application/json", serialize(res)); 
  }
  void handleWater(){
    // Haces los tenga que hacer 
  }
  void handleHelth() {
    JsonDocument res; 
    res["isEmpty"] = water_service.isEmpty(); 
    server.send(200, "application/json", serialize(res)); 
  }
  void handleSensors() {
    JsonDocument res; 
    parse_sensor(res); 
    server.send(200, "application/json", serialize(res)); 
  }
  // Cration
  void setup_routes() {
    add_headers(); 
    server.on("/get_status", HTTP_GET, wrapper(this, &HTTPServer::handleStatus)); 
    server.on("/helth", HTTP_GET, wrapper(this, &HTTPServer::handleHelth)); 
    server.on("/water-plant", HTTP_GET, wrapper(this, &HTTPServer::handleWater)); 
    server.on("/helth/sensors", HTTP_GET, wrapper(this, &HTTPServer::handleSensors)); 
    server.begin(); 
  }
  void start_server(){
    server.handleClient(); 
  }
  String serialize(JsonDocument & param){
    String body; 
    serializeJson(param, body); 
    return body; 
  }
  void add_headers(){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.sendHeader("Access-Control-Allow-Methods", "GET, POST, PUT");
    server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  }; 
}; 
#endif