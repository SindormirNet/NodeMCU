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

void miWeb() { 
  String web = "<!DOCTYPE HTML><html><body><form  action=''><input type=’text’  name='nombreDeMiCaja'/><input type='submit'/><br>";
  web + "Recibido:<br><br>";
  web + "Direccion: ";
  web + server.uri();
    web + "<br>Metodo: ";
      //Comprobar si recibimos los datos por GET o por POST
    if( server.method() == HTTP_GET ){
       web + "GET";
    }else{
       web + "POST";
    }  
    web + "<br>Argumentos: ";
    web + server.args();
    web + "<br>";

    for ( int i = 0; i < server.args(); i++ ) {
       web + " " + server.argName ( i ) + ": " + server.arg ( i ) +         "<br>";
    }

    web + "</form></body></html>";
    server.send ( 200, "html", web );
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


