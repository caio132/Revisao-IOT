#include <SPI.h>         // needed for Arduino versions later than 0018
#include <UIPEthernet.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <Servo.h>

Servo Servo1;

const int ledverde = A0;
const int ledamarelo = 9;
const int ledvermelho = 8;

const int buzzer = 7;

const int echo = 5;
const int trig = 4;

const int botao = 6;

int estadobotao = LOW;
int ultimoestadobotao = LOW;
int ultimoestadoled = LOW;

Ultrasonic ultrasonic(trig,echo);


byte mac[] = {
 0xDE, 0xAD, 0xBE, 0xFF, 0xFF, 0xED
};

char* servidor_mqtt = "192.168.2.19";
int porta_mqtt = 1883;

long lastReconnectAttempt = 0;

void mensagem_mqtt(char* topic, byte* payload, unsigned int length) {

char* payload_char = payload;
payload_char[length] = 0;
String payload_string = String(payload_char);

 String topicstring = String(topic);
 Serial.print("TOPIC: ");
 Serial.println(topicstring);
 Serial.print("PAYLOAD: ");
 Serial.println(payload_string);

if (topicstring == "portao" && payload_string == "abrir")
{
  Servo1.write(90);  
}

if (topicstring == "portao" && payload_string == "fechar")
{
  Servo1.write(0);  
}

}
EthernetClient ethernet_client;
PubSubClient pubsub(servidor_mqtt, porta_mqtt, mensagem_mqtt, ethernet_client);

boolean reconnect() {
  Serial.println("reconectando...");
  if (pubsub.connect("faculdade", "iot", "123")) {
    Serial.println("conectado");
     pubsub.publish("manda", "voltei");
    Serial.println("Voltei Enviado!");
    pubsub.subscribe("portao");

      }
  return pubsub.connected();
}

void setup() {
 Servo1.attach(3);
 Servo1.write(0);
 pinMode(ledverde,OUTPUT);
 pinMode(ledamarelo,OUTPUT);
 pinMode(ledvermelho,OUTPUT);
 pinMode(buzzer,OUTPUT);

 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);

 pinMode(botao,INPUT);
  
 Serial.begin(9600);
 if (!Ethernet.begin(mac)) {
    Serial.println("DHCP Failed");
  } else {
    Serial.println(Ethernet.localIP());
  }

if (pubsub.connect("faculdade","iot","123")){
    Serial.println("Conectado");
    pubsub.publish("manda", "hello world");
    Serial.println("Hello World Enviado!");
    pubsub.subscribe("portao");
  }
  else {
    Serial.println("MQTT Não esta conectado");
    } 
    lastReconnectAttempt = 0;
}



void loop() {
  if (!pubsub.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      Serial.println("reconectando...");
      lastReconnectAttempt = now;

      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
/*    digitalWrite(ledverde,HIGH);
    digitalWrite(ledamarelo,HIGH);
    digitalWrite(ledvermelho,HIGH);
    //tone(buzzer,1000);
    int distancia = ultrasonic.distanceRead();
    Serial.println(distancia);
    estadobotao = digitalRead(botao);
    Serial.print("botao: ");
    Serial.println(estadobotao);
    Servo1.write(110);
    delay(1000);
    digitalWrite(ledverde,LOW);
    digitalWrite(ledamarelo,LOW);
    digitalWrite(ledvermelho,LOW);
    //noTone(buzzer);
    Servo1.write(30);
    delay(1000);
    */
    pubsub.loop();
    
  }
int distancia = ultrasonic.distanceRead();
String distanciaString = String(distancia);
char distanciaChar[5];
distanciaString.toCharArray(distanciaChar,5);
Serial.println(distanciaChar);
delay(500);
pubsub.publish("distancia","123");
pubsub.subscribe("distancia");   

if (distancia >= 8)
{
  digitalWrite(ledverde,HIGH);
  digitalWrite(ledamarelo,LOW);
  digitalWrite(ledvermelho,LOW);
  
/*  tone(buzzer,1000);
  delay(1000);
  noTone(buzzer);
  delay(1000);
 */
}
if (distancia < 8 && distancia >= 4)
{
  digitalWrite(ledamarelo,HIGH);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledvermelho,LOW);
  tone(buzzer,750);
  delay(300);
  noTone(buzzer);
  delay(300);
   
}

if (distancia < 4)
{
  digitalWrite(ledvermelho,HIGH);
  digitalWrite(ledamarelo,LOW);
  digitalWrite(ledverde,LOW);
  tone(buzzer,1000);
  delay(150);
  noTone(buzzer);
  delay(150);
}

estadobotao = digitalRead(botao);
Serial.print("botao: ");
Serial.println(estadobotao);

if (estadobotao != ultimoestadobotao)
{
  if (estadobotao == HIGH) {
    
    if (ultimoestadoled == HIGH) {

       Servo1.write(90);
       ultimoestadoled = LOW;
      }
      else {
        Servo1.write(0);
        ultimoestadoled = HIGH;
        }
        
    }

}
ultimoestadobotao = estadobotao;


}

