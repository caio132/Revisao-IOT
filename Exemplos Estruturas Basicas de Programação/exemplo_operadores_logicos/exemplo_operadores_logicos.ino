// exemplo da utilização de operadores logicos

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
  // exemplo do OR
  if (leitura == "liga" || leitura == "on" )
  {
    digitalWrite(led,HIGH); 
  }
  //exemplo de AND
  if (leitura == "desliga" && led == 13)
  {
    digitalWrite(led,LOW);  
  }
  // o NOT , representado pela "!" faz somente a inversão
  // do que é verdadeiro para falso e vice-versa
}
}
