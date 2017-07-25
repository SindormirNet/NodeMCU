#define led D1
#define potenciometro A0

int valorSalida;
int lecturaAnalogica;

void loop() { 
 Serial.begin(9600);
}
void loop() { 
  lecturaAnalogica = analogRead(A0);
  
  valorSalida = map(lecturaAnalogica, 0, 1023, 0, 255);
  analogWrite(led, valorSalida);
  }