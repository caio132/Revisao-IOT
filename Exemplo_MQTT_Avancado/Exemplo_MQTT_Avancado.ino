#include <SPI.h>         // needed for Arduino versions later than 0018
#include <UIPEthernet.h>
#include <PubSubClient.h>

byte mac[] = {
 0xDE, 0xAD, 0xBE, 0xFF, 0xFF, 0xED
};

char* servidor_mqtt = "m11.cloudmqtt.com";
int porta_mqtt = 16345;

long lastReconnectAttempt = 0;

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

boolean reconnect() {
  Serial.println("reconectando...");
  if (pubsub.connect("faculdade", "tmdigras", "P5UZxfYbqz7r")) {
    Serial.println("conectado");
     pubsub.publish("manda", "voltei");
    Serial.println("Voltei Enviado!");
    pubsub.subscribe("recebe");

      }
  return pubsub.connected();
}

void setup() {
 Serial.begin(9600);
 if (!Ethernet.begin(mac)) {
    Serial.println("DHCP Failed");
  } else {
    Serial.println(Ethernet.localIP());
  }

if (pubsub.connect("faculdade","tmdigras","P5UZxfYbqz7r")){
    Serial.println("Conectado");
    pubsub.publish("manda", "hello world");
    Serial.println("Hello World Enviado!");
    pubsub.subscribe("recebe");
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
    pubsub.loop();
  }

}

