#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

int request_i = 0;
int response_i = 0;

String manageRequest(String request){
  
	//Nostramos el mensaje que nos ha llegado. 
	Serial.print("received: ");
	Serial.println(request);

	//Devolvemos el String para que sea enviado
	char response[60];
	sprintf(response, "Hola! este es el mensaje #%d desde Mesh_Node%d.", response_i++, ESP.getChipId());
	return response;
}

//Creamos un objeto de la malla. 
ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(ESP.getChipId(), manageRequest);

void setup(){
	Serial.begin(115200);
	delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Soy: ");
  Serial.println(ESP.getChipId());
	Serial.println();
	Serial.println();
	Serial.println("Inicializando el modo mesh...");

	//Inicializamos la malla
	mesh_node.begin();
}

void loop(){
  //aceptamos las peiticiones entrantes
	mesh_node.acceptRequest();

	//escaneamos otros nodes y les enviamos un mensaje
	char request[60];
	sprintf(request, "Hola nuevo! este es mi mensaje #%d soy Mesh_Node%d.", request_i++, ESP.getChipId());
	mesh_node.attemptScan(request);
	delay(1000);
}
