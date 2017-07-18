#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "sindormir.net";
const char* password = "espaciomiscela";

ESP8266WebServer server(80);


void miWeb(void) { 
  //cabeceras de la pagina para que el navegador sepa que se trata de una pagina web y las etiquetas de apertura de la misma
  String web = "<!DOCTYPE HTML><html><body>";

  //Comprobamos si el botón 1 esta pulsado o no y en función de eso mostramos uno u otro mensaje
  if(digitalRead(D2)){
    web = web += "<h1>BOTON 1 PULSADO</h1>";
  }else{
    web = web += "<h1>BOTON 1 SIN PULSAR</h1>";
  }

  //Comprobamos si el botón 2 esta pulsado o no y en función de eso mostramos uno u otro mensaje
  if(digitalRead(D3)){
    web = web += "<h1>BOTON 2 Pulsado</h1>";
  }else{
    web = web += "<h1>BOTON 2 SIN PULSAR</h1>";
  }

  //etiquetas de cierre de la web
   web = web += "</body></html>";

   //Enviamos la web al servidor que tenemos activo y escuchando en el puerto 80 de nuestro ESP8266
   server.send(200, "html",web);
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
