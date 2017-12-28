const int led_verde = 5;
const int led_amarelo = 6;
const int led_vermelho = 7;

const int buzina = 8;
int frequencia = 0;
int tempo=0;
const int botao = 4;
const int botao1 = 3;
int ativado;
int desativado;

const int sensor_temperatura = A0;
int leitura_sensor;
float temperatura;

void setup() {
  // put your setup code here, to run once:

  pinMode(buzina, OUTPUT);

  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);

  pinMode(botao, INPUT);
  pinMode(botao1, INPUT);

  analogReference(INTERNAL);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  leitura_sensor = analogRead(sensor_temperatura);
  temperatura = leitura_sensor * 0.1075268817204301;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  Serial.print("BotaoAtivado: ");
  Serial.println(ativado);
  ativado = digitalRead(botao);

  Serial.print("BotaoDesativado: ");
  Serial.println(desativado);
  desativado = digitalRead(botao1);
  delay(1000);
  if ( temperatura < 28 )
  {
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, LOW);
    noTone(buzina);
  }
  if ( temperatura >= 28 && temperatura < 30 )
  {
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, LOW);
    noTone(buzina);
  }
  if ( temperatura > 30 )
  {
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, LOW);
    tone(buzina, 3000);
  }
  if ( ativado == HIGH ){
    while (desativado != HIGH)
    {
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarelo, LOW);
      for (frequencia = 150; frequencia < 1800; frequencia += 1) 
  {
    tone(buzina, frequencia, tempo); 
    delay(1);
  }
  for (frequencia = 1800; frequencia > 150; frequencia -= 1) 
  {
    tone(buzina, frequencia, tempo); 
    delay(1);
  }
      desativado = digitalRead(botao1);
    }
  }
}
