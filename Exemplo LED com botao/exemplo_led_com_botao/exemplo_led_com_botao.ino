// exemplo de acender e apagar um led utilizando um botao

const int ledverde = 7;
const int botao = 5;
int estadobotao;
void setup() {
pinMode(ledverde,OUTPUT);
pinMode(botao,INPUT);
}

void loop() {
estadobotao = digitalRead(botao);
if (estadobotao == HIGH)
{
digitalWrite(ledverde,HIGH);
}
else {
  
digitalWrite(ledverde,LOW);  
  }

}
