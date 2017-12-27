const int led = 7;
int leitura;
int buzina = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(buzina, OUTPUT);
  Serial.begin(9600);
  Serial.println("Iniciando a serial. . .");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    leitura = Serial.parseInt();
    Serial.println(leitura);
    switch (leitura) {
      case 1:
        tone(buzina, 3000);
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        delay(2000);
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        delay(2000);
        break;
      case 2:
        tone(buzina, 15000);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
        break;
      case 3:
        tone(buzina, 25000);
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);
        break;
      default:
        noTone(buzina);
        digitalWrite(led,LOW);
        break;
    }
    
  }
}
