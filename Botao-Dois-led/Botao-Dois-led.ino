const int botao = 5;
const int ledvermelho = 7;
const int ledverde = 2;

int estadobotao ;
int estadoled ;
int ultimoestadobotao ;
int ultimoestadoled ;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledverde, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadobotao = digitalRead(botao);

  if (estadobotao != ultimoestadobotao)
  {
    if (estadobotao == HIGH)
    {
      if (ultimoestadoled == HIGH)
      {
        digitalWrite(ledvermelho, LOW);
        digitalWrite(ledverde, HIGH);
        ultimoestadoled = LOW;
      }

      else
      {
        digitalWrite(ledvermelho, HIGH);
        digitalWrite(ledverde, LOW);
        ultimoestadoled = HIGH;
      }

    }
  }
  ultimoestadobotao = estadobotao;
}
