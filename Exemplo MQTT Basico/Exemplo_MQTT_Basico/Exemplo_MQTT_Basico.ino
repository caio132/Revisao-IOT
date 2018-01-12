#include <SPI.h>         // needed for Arduino versions later than 0018
#include <UIPEthernet.h>
#include <PubSubClient.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xFF, 0xFF, 0xED};

char* servidor_mqtt = "m14.cloudmqtt.com";
int porta_mqtt =  19568;

void mensagem_mqtt(char* topic, byte* payload, unsigned int length) {

char* payload_char = payload;
payload_char[length] = 0;
String payload_string = String(payload_char);

 String TopicString = String(topic);
 Serial.print("TOPIC: ");
 Serial.println(TopicString);
 Serial.print("PAYLOAD: ");
 Serial.println(payload_string);
}

EthernetClient ethernet_client;
PubSubClient pubsub(servidor_mqtt, porta_mqtt, mensagem_mqtt, ethernet_client);

void setup() {
 Serial.begin(9600);
 if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
}

if (pubsub.connect("arduino1","cwjyyhkk","zNHgJ7bUqihZ")){
    Serial.println("Conectado");
    pubsub.publish("manda", "hello world");
    Serial.println("Hello World Enviado!");
    pubsub.subscribe("recebe");
  }
  else {
    Serial.println("MQTT Não esta conectado");
    } 
}



void loop() {
  pubsub.loop();
}

