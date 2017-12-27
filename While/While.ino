void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Iniciando a serial...");

  int contador=0;
  while ( contador <= 50 )
  {
    Serial.print("contador");
    Serial.println(contador);
    contador++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
