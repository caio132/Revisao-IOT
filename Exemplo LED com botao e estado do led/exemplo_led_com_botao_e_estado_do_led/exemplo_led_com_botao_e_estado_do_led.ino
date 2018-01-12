// exemplo de acender e apagar um led utilizando um botao salvando o estado do led

const int ledverde = 7;
const int botao = 5;
int estadobotao = LOW;
int ultimoestadobotao = LOW;
int ultimoestadoled = LOW;
int estadoled = LOW;

void setup() {
pinMode(ledverde,OUTPUT);
pinMode(botao,INPUT);
Serial.begin(9600);
}

void loop() {
estadobotao = digitalRead(botao);

if (estadobotao != ultimoestadobotao)
{
  if (estadobotao == HIGH) {
    
    if (ultimoestadoled == HIGH) {

       digitalWrite(ledverde,LOW);
       ultimoestadoled = LOW;
      }
      else {
        digitalWrite(ledverde,HIGH);
        ultimoestadoled = HIGH;
        
        }
        
    }

}
ultimoestadobotao = estadobotao;
}
