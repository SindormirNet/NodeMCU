#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "sindormir.net";
const char* password = "espaciomiscela";

ESP8266WebServer server(80);


void miWeb(void) { 
  String web = "<!DOCTYPE HTML><html><head><title>Control con Botones</title></head><body>";
  web = web + "<form action=\"\">";
  web = web + "<input type=\"submit\" value=\"1\" name=\"led\"/>";
  web = web + "<input type=\"submit\" value=\"2\" name=\"led\"/>";
  web = web + "</form></body></html>";

  server.send(200, "html",web);  
  
  server.method() == HTTP_GET;  

  String led = server.arg(0);
  int miLed = led.toInt();

  if(miLed == 1){
    digitalWrite(D5,HIGH);
  }else if(miLed == 2){
    digitalWrite(D6,HIGH);
  }else{
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
  }
  
  delay(1);
}


void setup() {
  // put your setup code here, to run once:
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



  server.on("/", miWeb);



  server.begin();
  Serial.println("HTTP server started");

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
