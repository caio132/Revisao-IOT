const int led_verde = 5;
const int led_amarelo = 6;
const int led_vermelho = 7;
//
const int buzina = 8;
//
const int botao = 4;
const int botao1 = 3;
int estadobotao;
int desativado;
int ultimoestadoled;
int ultimoestadobotao;
//
const int sensor_temperatura = A0;
int leitura_sensor;
float temperatura;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzina, OUTPUT);
  //
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  //
  pinMode(botao, INPUT);
  pinMode(botao1, INPUT);
  //
  analogReference(INTERNAL);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  leitura_sensor = analogRead(sensor_temperatura);
  temperatura = leitura_sensor * 0.1075268817204301;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  //
  Serial.print("BotaoAtiva: ");
  Serial.println(estadobotao);
  //
  Serial.print("BotaoDesativa: ");
  Serial.println(desativado);
  delay(1000);
  //
  estadobotao = digitalRead(botao);
  desativado = digitalRead(botao1);
  //

  if ( temperatura < 28)
  { digitalWrite(led_verde, HIGH);
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, LOW);

    noTone(buzina);
  }
  if ( temperatura >= 28 && temperatura < 30)
  {
    digitalWrite (led_amarelo, HIGH);
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_verde, LOW);

    noTone(buzina);
  }
  if (temperatura > 30)
  {
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, LOW);
    tone(buzina, 2000);
  }

  if (estadobotao == HIGH) {
    while (desativado != HIGH) {

      digitalWrite(led_vermelho, HIGH);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_verde, LOW);
      tone(buzina, 2000);
      desativado = digitalRead(botao1);

    }
  }


}
