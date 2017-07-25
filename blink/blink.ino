void setup(){
	pinMode(D7, OUTPUT); //Indicamos que nuestro pin 7 es una salida
}

void loop(){
	digitalWrite(7, HIGH); 	//Encendemos el led
	delay(1000);//le pedimos que espere 1000ms (1s) antes de realizar la siguiente orden	
	digitalWrite(7, LOW);	//Apagamos el led
	delay(1000);			//Esperamos otros 1000ms (1s) 
}
