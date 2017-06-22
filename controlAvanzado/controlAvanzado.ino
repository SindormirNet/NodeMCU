#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "sindormir.net";
const char* password = "espaciomiscela";

ESP8266WebServer server(80);
Servo miServo;

void miWeb(void) { 
  String web = "<!DOCTYPE HTML><html><head><title>Control con Botones</title></head><body>";
  web = web += "<form action=\"\">";
  web = web += "<input type=\"submit\" value=\"1\" name=\"led\"/>";
  web = web += "<input type=\"submit\" value=\"2\" name=\"led\"/>";
  web = web += "<input type=\"range\" min=\"0\" max=\"180\" step=\"1\" name=\"angulo\"/>";
  web = web += "<input type=\"submit\"/>";
  web = web += "</form></body></html>";

  server.send(200, "html",web);  
  
  server.method() == HTTP_GET;  

  //Guardamos el argumento en una variable y la convertimos en un int
  String parametro = server.arg(0);
  int miParametro = parametro.toInt();

//Comprobamos si el usuario nos ha enviado una orden para los led (si el nombre del argumento es led) o para el servo (si es angulo)  
if(server.argName(0)=="led"){
  //Si el nombre del argumento es led realizamos las acciones de control de los led
  if(miParametro == 1){
    digitalWrite(D5,HIGH);
  }else if(miParametro == 2){
    digitalWrite(D6,HIGH);
  }else{
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
  }
}else if(server.argName(0)=="angulo"){
  //Si el nombre del argumento es angulo la orden es para el servo y la realizamos aquí. 
  miServo.write(miParametro);
}
  delay(1);
}


void setup() {
  // Configuraciones e inicializaciones. 
  miServo.attach(D2);
  miServo.write(90);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  
  // Esperamos a estar conectados. 
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
