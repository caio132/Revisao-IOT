// exemplo da utilização do IF e ELSE

// declaração das variaveis
const int led = 13;
String leitura;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.print("Iniciando a serial ...");
}

void loop() {
if (Serial.available())
{
  leitura = Serial.readString();
  Serial.println(leitura);
  if (leitura == "liga")
  {
    digitalWrite(led,HIGH); 
  }
  if (leitura == "desliga")
  
  {
    digitalWrite(led,LOW);  
  }

}
}
