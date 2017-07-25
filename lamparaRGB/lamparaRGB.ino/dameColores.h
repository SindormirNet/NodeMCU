unsigned int hexToDec(String hexString) {
  
  unsigned int decValue = 0;
  int nextInt;
  
  for (int i = 0; i < hexString.length(); i++) {
    
    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);
    
    decValue = (decValue * 16) + nextInt;
  }
  
  return decValue;
}

//Funciones para extraer colores
int* dameColores(String colores){
  String R,G,B;
  int Ri, Gi,Bi;
  
  //Busca el comienzo del codigo hexadecimal de color
  int firstHastag = colores.indexOf('#');
  Serial.print("Primera respuesta: ");Serial.println(firstHastag);
  
  //Extrae los colores codificados en Hexadecimal en R-G-B
  R = colores.substring(firstHastag+1, firstHastag+3);
  G = colores.substring(firstHastag+3, firstHastag+5);
  B = colores.substring(firstHastag+5, firstHastag+7);
  Serial.print("Color en Hex: ");Serial.print(R);Serial.print("-"); Serial.print(G);Serial.print("-");Serial.println(B);
  
  //Convierte los valores de color hexadecimales en decimales
  R = hexToDec(R);
  G = hexToDec(G);
  B = hexToDec(B);  
  Serial.print("Color en RGB: ");Serial.print(R);Serial.print("-"); Serial.print(G);Serial.print("-");Serial.println(B);
  
  //Transforma el String en valores integer
  Ri = R.toInt();
  Gi = G.toInt();
  Bi = B.toInt();  
  int valColores[] = {Ri, Gi, Bi};
  return valColores;
}
