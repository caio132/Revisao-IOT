// OBJETIVO:

// Utilizar IF , Botao, Buzzer , LED, Sensor de Temperatura

// Utilizar o Botao para ativar o alarme de incendio manualmente

// Utilizar o sensor de temperatura para disparar o alarme 

// Utilizar dois botoes , um para ativar o alarme manualmente , o segundo para desligar o alarme

const int ledverde = 6;
const int ledamarelo = 5;
const int ledvermelho = 4;
const int btn_liga_alarme = 10;
const int btn_desliga_alarme = 7;


const int buzzer = 12;

int estado_btn_liga_alarme = LOW;
int estado_btn_desliga_alarme = LOW;

int estadoled = LOW;
int ultimoestadoled = LOW;

int ultimo_estado_botao_alarme = LOW;

int botao_liga;
int botao_desliga;

// temperatura
const int sensor_temperatura = A0;
int leitura_sensor = 0;
float temperatura;

void setup() {
analogReference(INTERNAL);
Serial.begin(9600);
pinMode(ledvermelho,OUTPUT);
pinMode(ledamarelo,OUTPUT);
pinMode(ledverde,OUTPUT);
pinMode(btn_liga_alarme,INPUT);
pinMode(btn_desliga_alarme,INPUT);
pinMode(buzzer,OUTPUT);

}

void loop() {

estado_btn_liga_alarme = digitalRead(btn_liga_alarme);

Serial.print("btn_liga_alarme: ");
Serial.println(estado_btn_liga_alarme);

estado_btn_desliga_alarme = digitalRead(btn_desliga_alarme);

Serial.print("btn_desliga_alarme: ");
Serial.println(estado_btn_desliga_alarme);

leitura_sensor = analogRead(sensor_temperatura);
temperatura = leitura_sensor * 0.1075268817204301;


  
  if (estado_btn_desliga_alarme == HIGH) {
        digitalWrite(ledverde,HIGH);   
        digitalWrite(ledamarelo,LOW);
        digitalWrite(ledvermelho,LOW);
        noTone(buzzer);
        botao_desliga = 0;
      }   

  else {
    botao_desliga = 1;
    
    }
  
  if (estado_btn_liga_alarme == HIGH) 
    {
      while (estado_btn_desliga_alarme != HIGH)
      {
       digitalWrite(ledverde,LOW);   
        digitalWrite(ledamarelo,LOW);
        digitalWrite(ledvermelho,HIGH);
        tone(buzzer,500);
      botao_liga = 0;
      estado_btn_desliga_alarme = digitalRead(btn_desliga_alarme);
      }
    }
    else {
      
     botao_liga = 1;
      }

Serial.print("Temperatura: ");
Serial.println(temperatura);
delay(1000);

 if (temperatura > 30 &&  botao_liga == 1) {
  
   digitalWrite(ledverde,LOW);   
        digitalWrite(ledamarelo,LOW);
        digitalWrite(ledvermelho,HIGH);
        tone(buzzer,500);
  }

 if (temperatura <= 28 &&  botao_desliga == 1) {
  
      digitalWrite(ledverde,HIGH);   
        digitalWrite(ledamarelo,LOW);
        digitalWrite(ledvermelho,LOW);
        noTone(buzzer);
  }
 if (temperatura > 28 && temperatura < 30)
 {
    digitalWrite(ledverde,LOW);   
        digitalWrite(ledamarelo,HIGH);
        digitalWrite(ledvermelho,LOW);
        noTone(buzzer);
  
  }




}
