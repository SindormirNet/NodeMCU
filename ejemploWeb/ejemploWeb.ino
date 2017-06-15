#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "sindormir.net";
const char* password = "espaciomiscela";

ESP8266WebServer server(80);

void miWeb() {
  server.send(200, "text/plain", "HOLA MUNDO!");
}

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.RSSI());


  server.on("/", miWeb);



  server.begin();
  Serial.println("HTTP server started");
}

void loop(){
  server.handleClient();
}
