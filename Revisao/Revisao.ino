const int botao = 5;
int estadobotao = LOW;
const int (led_vermelho) = 7;
int estadoled = LOW;
int estadoanterior = LOW;

void setup() {
  // put your setup code here, to run once:

pinMode(led_vermelho,OUTPUT);
pinMode(botao,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

estadobotao = digitalRead(botao);
estadoled = digitalRead(led_vermelho);


if (estadobotao == HIGH) {

    if (estadoanterior == LOW) {
      digitalWrite(led_vermelho,HIGH);
      estadoanterior = HIGH;
    }
  else

      {digitalWrite(led_vermelho,LOW);
      estadoanterior = LOW; }

}


  
    
