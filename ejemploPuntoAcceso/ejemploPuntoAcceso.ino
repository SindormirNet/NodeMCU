#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Nombre y contraseña del punto de acceso que queremos crear. */
const char *ssid = "soyUnESP2966";
const char *password = "esteesmimodulo";

//Creamos un objeto de la librería WebServer y le decimos que escuche en el puerto 80 de ESP2866
ESP8266WebServer server(80);

//Funcion que define el contenido de la web que vamos a mostrar
void miWeb() {
  server.send(200, "text/html", "<h1>¡ESTAS CONECTADO A TU PROPIA WIFI EN UN ESP8266!</h1>");
}

void setup() {
  //Iniciamos la comunicacion serial
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configurando punto de acceso...");

  //Lanzamos la wifi con el nombre y la contraseña previamente definida
  WiFi.softAP(ssid, password);

  //Nos auto-asignamos una IP
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Direccion IP: ");
  Serial.println(myIP);

  //Lanzamos nuestra web al servidor que esta escuchando en el puerto 80
  server.on("/", miWeb);
  server.begin();
  Serial.println("Servido HTTP iniciado");
}

void loop() {
  server.handleClient();
}
