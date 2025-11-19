#ifndef INITWIFI_H
#define INITWIFI_H
#include <WiFi.h>
#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"
void init_wifi()
{
  Serial.println();
  WiFi.mode(WIFI_STA); // Estacion
  // WiFi.mode(WIFI_AP); // Punto de Acceso
  // WiFi.mode(WIFI_MODE_APSTA); // Ambos
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Conectar WiFi id y passwd
  Serial.print("Conectando a ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED)
  { // Espera a que esté conectado
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println();
    Serial.println();
    Serial.println("Connected to WIFI!!");
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
#endif