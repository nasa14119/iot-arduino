// library 
#include "http_server.ino"
#include "wifi_start.ino"
// definition 
// global var
HTTPServer handler; 
// program
void setup() {
  Serial.begin(115200); 
  init_wifi(); 
  setup_sensor(); 
  handler.setup_routes(); 
  Serial.println("Web Server Listening..."); 
}

void loop() {
  handler.start_server(); 
  delay(200); 
}
