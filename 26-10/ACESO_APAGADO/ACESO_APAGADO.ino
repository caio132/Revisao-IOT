int led_vermelha = 10;
int led_amarela = 7;

void setup() {
  // put your setup code here, to run once:

pinMode(led_vermelha,OUTPUT);
pinMode(led_amarela,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(led_vermelha,HIGH);
delay(100);
digitalWrite(led_vermelha,LOW);
delay(100);

digitalWrite(led_amarela,HIGH);
delay(100);
digitalWrite(led_amarela,LOW);
delay(100);
}
