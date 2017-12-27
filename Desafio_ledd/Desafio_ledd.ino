const int led_vermelha = 7;
const int led_amarela = 8;
const int led_verde = 2;
const int botao = 5;

int estadobotao ;
int ultimobotao ;
void setup() {
  // put your setup code here, to run once:

  pinMode(led_vermelha, OUTPUT);
  pinMode(led_amarela, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  estadobotao = digitalRead(botao);
  Serial.println(estadobotao);
    if (estadobotao != ultimobotao)
  {
    if (estadobotao = HIGH)
    {
      if (ultimobotao == HIGH)
      {
        digitalWrite(led_verde, HIGH);
        delay(700);
        digitalWrite(led_verde, LOW);
        
        digitalWrite(led_amarela, HIGH);
        delay(200);
        digitalWrite(led_amarela, LOW);
        
        digitalWrite(led_vermelha, HIGH);
        delay(500);
        digitalWrite(led_vermelha, LOW);
        estadobotao = HIGH;
      }
    }
  }
  ultimobotao = estadobotao;
  
    }


