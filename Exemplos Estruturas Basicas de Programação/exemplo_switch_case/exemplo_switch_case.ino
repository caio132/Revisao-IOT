// exemplo da utilização do SWITCH CASE

// declaração das variaveis
const int led = 13;
int leitura;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.println ("Iniciando a serial ...");
}

void loop() {
if (Serial.available())
{
  leitura = Serial.parseInt();
  Serial.println(leitura);
  switch (leitura) {
   case 1:
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
    delay(2000);
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
    break; 
   case 2:
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    break; 
   case 3:
   digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    break; 
   default:
      digitalWrite(led,LOW);
      break;
    }
}
}
