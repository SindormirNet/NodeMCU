/*
*
*Plantilla para sketch con un ESP8266 con servicio web. 
*
*
*
 */

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char *ssid = "SSID";
const char *password = "password";

ESP8266WebServer server (80);

void miWeb() {
//En esta función definiremos como será nuestra web. 
String web;

  server.send ( 200, "text/plain", web);
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

	server.on ( "/", miWeb );
	server.begin();
	Serial.println ( "HTTP server iniciado" );
}

void loop () {
	server.handleClient();
}


