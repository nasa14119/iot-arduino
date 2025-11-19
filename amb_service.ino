#include "DHTesp.h"
#define SENSOR_PIN 0
DHTesp sensor; 
void setup_sensor() {
  sensor.setup(SENSOR_PIN, DHTesp::DHT11); 
}; 
std::pair<float, float> get_amb(){
  return {10.0f,50.0f}; 
  // return {sensor.getTemperature(), sensor.getHumidity()}; 
}; 