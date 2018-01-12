// exemplo de acender e apagar um led 

const int ledverde = 7;

void setup() {
pinMode(ledverde,OUTPUT);
}

void loop() {
digitalWrite(ledverde,HIGH);
delay(1000);
digitalWrite(ledverde,LOW);
delay(1000);
}
