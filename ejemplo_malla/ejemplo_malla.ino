#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

#define frecuencia 33
int miTurno = 2;

String manageRequest(String request){
  int turno = request.toInt();
  
  //Si recibimos nuestro turno mandamos el sonido 
  if(turno == miTurno){
    analogWrite(D3, frecuencia);
  }else{
    //Si no es nuestro turno paramos el sonido 
    digitalWrite(D3, LOW);
  }

  //Realizamos un cast para poder sumarle uno al valor recibido
  
  turno = turno + 1;

  //Realizamos otro Cast a String para 
  String response = String(turno,DEC);
  return response;
}

ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(ESP.getChipId(), manageRequest);

void setup() {
  Serial.begin(115200);
  mesh_node.begin();

}

void loop() {
  mesh_node.acceptRequest();
  String response = "Hola!";
  mesh_node.attemptScan(response);
}
