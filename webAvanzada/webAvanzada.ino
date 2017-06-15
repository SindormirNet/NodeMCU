#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "sindormir.net";
const char* password = "espaciomiscela";

ESP8266WebServer server(80);

void miWeb() {
  server.send(200, "html", "<html>\<head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>Curso ESP8266 -  Sindormir.net</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Esta web esta en un  ESP8266!</h1>\    
  </body>\
  </html>");
}

void about(){
    server.send(200, "html", "<html>\<head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>Curso ESP8266 -  Sindormir.net</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Soy Nano y hago web en un ESP8266</h1>\    
  </body>\
  </html>");
}

void pagError(){
  String message = "No tengo esa web :-(\n\n";
  message += "URI: ";
  message += server.uri();


  server.send ( 404, "text/plain", message );
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
  server.on("/about", about);
  server.onNotFound (pagError);


  server.begin();
  Serial.println("HTTP server started");
}

void loop(){
  server.handleClient();
}
