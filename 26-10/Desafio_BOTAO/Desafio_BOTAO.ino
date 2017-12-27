const int botao = 4;
int estadobotao ;
const int led_vermelho = 6;

void setup() {
  // put your setup code here, to run once:

pinMode(led_vermelho,OUTPUT);  
pinMode(botao,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

estadobotao = digitalRead(botao);
Serial.println(estadobotao);

if(estadobotao == HIGH) {
  digitalWrite(led_vermelho,HIGH);
 }
  
else 

  {digitalWrite(led_vermelho,LOW);
    
 }
}
