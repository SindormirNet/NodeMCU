#include <SPI.h>
#include <WiFi.h>

char ssid[] = "sindormir.net";    // Nombre de la wifi (SSID)
char pass[] = "espaciomiscela";  // Password de la wifi

const int numLed = 10; 

int intensidad; 
int senal;


void setup() {
  //Iniciamos la comunicacion serial a 9600 baudios
  Serial.begin(9600);
  
//Mostramos por consola a donde tratamos de conectar
  Serial.print("Intentando conectar a la red: ");
  Serial.println(ssid);
   
    //Esta linea realiza la conexión a la red que hemos indicado con la contraseña que le hemos dado
  WiFi.begin(ssid, pass);

  //Este bucle se ejecuta hasta que la conexión a la wifi se complete con exito  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    
    //Espramos 10 segundos para que la conexion se estabilice
    delay(500);
  }

  //Una vez nos hemos conectado mostramos por consola la IP que nos ha dado el router
  Serial.print("Conectado a la red ");
  Serial.println(WiFi.SSID());
  Serial.print("Con la IP ");
  Serial.println(WiFi.localIP());
}

void loop() {

intensidad = WiFi.RSSI();//Almacenamos la intensidad de la red en una variable
senal = map(intensidad, 0, -80, 0, 10); //mapeamos los valores para pasarlos de un rango de 0 a -80 a otro de 0 a 10

 //evalualuamos los la variable senial para saber la potencia de la wifi y actuar en consecuencia
switch(senal){

  case 0: 

    digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

    case 1: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

  case 3: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

  case 4: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);    
    digitalWrite(D2,HIGH);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

  case 5: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

    case 6: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

  case 7: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

  case 8: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);
    digitalWrite(D8,LOW);
    
  break;

  case 9: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,HIGH);
    digitalWrite(D8,LOW);
    
  break;

  case 10: 

    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,HIGH);
    digitalWrite(D8,HIGH);
    
  break;
  
  }

/*
 * Solucion al reto: Realizar el mismo programa sin hacer uso de condicionales
 * 
for(int i = 0; i<= senal; i++){
      digitalWrite(i,HIGH);
      }
for(int i = senal+1; i<=numLed;i++){
      digitalWrite(i,LOW);
      }
*/

}
