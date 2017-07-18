#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "..........";
const char* password = "..........";

void setup() {
  Serial.begin(9600);
  Serial.println("Cargando");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);
    Serial.print(".");
  }

  // Puerto para la programación por OTA (por defecto 8266)
  // ArduinoOTA.setPort(8266);

  // Nombre amigable para nuestro ESP via OTA
  // ArduinoOTA.setHostname("myesp8266");

  // Password para programación por OTA
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Error de Autentificacion");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Error de inicializacion");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Fallo en la conexion");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Fallo en la recepcion");
    else if (error == OTA_END_ERROR) Serial.println("Fallo en la finalizacion");
  });
  ArduinoOTA.begin();
  Serial.println("Preparado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();
}
