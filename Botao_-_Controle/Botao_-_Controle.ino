const int botao = 5;
const int ledvermelho = 7;

int estadobotao;
int ultimoestadobotao;
int estadoled;
int ultimoestadoled;


void setup() {
  // put your setup code here, to run once:
pinMode ( botao, INPUT);
pinMode ( ledvermelho, OUTPUT);

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
        ultimoestadoled = LOW;
      }

      else
      {
        digitalWrite(ledvermelho, HIGH);
        ultimoestadoled = HIGH;

      }

    }

  }
  ultimoestadobotao = estadobotao;
}
