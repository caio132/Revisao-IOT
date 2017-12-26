const int led_vermelha = 10;
const int led_amarela = 7;
int vermelho = 1;
int amarelo = 0;
void setup() {
  // put your setup code here, to run once:

pinMode(led_vermelha,OUTPUT);
pinMode(led_amarela,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

if(vermelho > amarelo) {

digitalWrite(led_vermelha,HIGH);
delay(100);}

else

 {digitalWrite(led_amarela,HIGH);
delay(100);

 }
}
