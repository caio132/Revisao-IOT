int led_vermelha = 7;
int led_amarela = 8;
int led_verde = 2;

void setup() {
  // put your setup code here, to run once:

pinMode(led_vermelha,OUTPUT);
pinMode(led_amarela,OUTPUT);
pinMode(led_verde,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(led_verde,HIGH);
delay(7000);
digitalWrite(led_verde,LOW);
delay(7000);

digitalWrite(led_amarela,HIGH);
delay(2000);
digitalWrite(led_amarela,LOW);
delay(2000);

digitalWrite(led_vermelha,HIGH);
delay(5000);
digitalWrite(led_vermelha,LOW);
delay(5000);
}

