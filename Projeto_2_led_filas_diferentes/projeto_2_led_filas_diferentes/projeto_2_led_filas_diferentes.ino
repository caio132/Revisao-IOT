#include <Ethernet.h>
#include <PubSubClient.h>

const int ledverde = 8;

byte mac[] = {
 0xDE, 0xAD, 0xBE, 0xEF, 0xAA, 0xCC
};

char* servidor_mqtt = "m11.cloudmqtt.com";
int porta_mqtt = 16345;

void mensagem_mqtt(char* topic, byte* payload, unsigned int length) {
// Serial.println(payload);
  char* payload_char = payload;
     String payload_string = String(payload_char);
   int payload_int = payload_string.toInt();  
    
    Serial.println(payload_int);

//teste string topic
String TopicString = String(topic);
  Serial.println(TopicString);

  
  if (TopicString == "recebe" && payload_int == 1) {
     liga_led_verde();
    }
  
  if (TopicString == "recebe" && payload_int == 0) {
     desliga_led_verde();
    }

}
EthernetClient ethernet_client;
PubSubClient pubsub(servidor_mqtt, porta_mqtt, mensagem_mqtt, ethernet_client);

void liga_led_verde (){
 digitalWrite(ledverde,HIGH);
}
void desliga_led_verde (){
 digitalWrite(ledverde,LOW);
}


void declara_led() {
 pinMode(ledverde,OUTPUT);
  
}
void printIPAddress()
{
Serial.print("ip = ");
Serial.println(Ethernet.localIP());
Serial.print("subnet mask = ");
Serial.println(Ethernet.subnetMask());
Serial.print("gateway = ");
Serial.println(Ethernet.gatewayIP());
Serial.print("dns = ");
Serial.println(Ethernet.dnsServerIP());


  Serial.println();
}

void setup() {
 Serial.begin(9600);
 declara_led();
 if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
}
printIPAddress();

if (pubsub.connect("faculdade","tmdigras","P5UZxfYbqz7r")){
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

