// exemplo de acender e apagar um led e tocando o buzzer utilizando um botao e salvando o estado do led

const int ledverde = 7;
const int botao = 5;
const int buzina = 3;

int estadobotao = LOW;
int ultimoestadobotao = LOW;
int ultimoestadoled = LOW;
int estadoled = LOW;

void setup() {
pinMode(ledverde,OUTPUT);
pinMode(botao,INPUT);
pinMode(buzina,OUTPUT);
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
       noTone(buzina);
      }
      else {
        digitalWrite(ledverde,HIGH);
        ultimoestadoled = HIGH;
        tone(buzina,1000);
        
        }
        
    }

}
ultimoestadobotao = estadobotao;
}
