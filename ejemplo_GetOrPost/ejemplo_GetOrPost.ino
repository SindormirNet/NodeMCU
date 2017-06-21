/*
*
*Este sketch muestra una web que a su vez informa de los argumentos que ha recibido, especificando nombre, valor y metodo de recepción. 
*
*
*
 */

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char *ssid = "sindormir.net";
const char *password = "espaciomiscela";

ESP8266WebServer server (80);

void handleRoot() {
	String message = "Recibido:\n\n";
  message += "Direccion: ";
  message += server.uri();
  message += "\nMetodo: ";
  
  //Comprobar si recibimos los datos por GET o por POST
  if( server.method() == HTTP_GET ){
    message +="GET";
  }else{
    message +="POST";
  }
  
  message += "\nArgumentos: ";
  message += server.args();
  message += "\n";

  for ( int i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send ( 200, "text/plain", message );
}



void setup () {
	Serial.begin ( 115200 );
	WiFi.begin ( ssid, password );
	Serial.println ( "" );

	// Wait for connection
	while ( WiFi.status() != WL_CONNECTED ) {
		delay ( 500 );
		Serial.print ( "." );
	}

	Serial.println ( "" );
	Serial.print ( "Conectado a: " );
	Serial.println ( ssid );
	Serial.print ( "con la IP: " );
	Serial.println ( WiFi.localIP() );

	server.on ( "/", handleRoot );
	server.begin();
	Serial.println ( "HTTP server iniciado" );
}

void loop () {
	server.handleClient();
}


