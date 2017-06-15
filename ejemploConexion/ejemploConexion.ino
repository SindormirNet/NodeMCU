#include <SPI.h>
#include <WiFi.h>

char ssid[] = "sindormir.net";    // Nombre de la wifi (SSID)
char pass[] = "espaciomiscela";  // Password de la wifi

//int status = WL_IDLE_STATUS;     // Esta variable almacenará el estado de la conexion

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
  // En esta ocasion no pondremos nada en el loop

}
