// este include é para as bibliotecas necessárias para shield ethernet
#include <Ethernet.h>

// este include é para as bibliotecas necessárias para o funcionamento do MQTT
#include <PubSubClient.h>

// primeiro passo : declarar as variaves do programa
const int ledverde = 2;
const int ledamarelo = 3;
const int ledvermelho = 4;
const int botao = 10;
int estadobotao = LOW ;
int estadoled = LOW;
int ultimoestadobotao = LOW;

// criar o mac address 
const byte mac[] = {0xDE, 0xED, 0xBE, 0xEF, 0xAA, 0xBB};
EthernetClient ethClient;

// servidor MQTT
const char* server = "m11.cloudmqtt.com";
const int port = 16345;

//reconexao do MQTT
long lastReconnectAttempt = 0;


void whenMessageReceived(char* topic, byte* payload, unsigned int length) {
  // Converter pointer do tipo `byte` para typo `char`
  char* payloadAsChar = payload;
  // Workaround para pequeno bug na biblioteca
  payloadAsChar[length] = 0;
  // Converter em tipo String para conveniência
  String msg = String(payloadAsChar);
  // https://www.arduino.cc/en/Reference/StringToInt
  int msgComoNumero = msg.toInt();

  Serial.print("Topic received: ");
  Serial.println(topic);
  Serial.print("Message: ");
  Serial.println(msg);

  // Dentro do callback da biblioteca MQTT,
  // devemos usar Serial.flush() para garantir que as mensagens serão enviadas
  delay(1000);
  //Serial.flush();

  Serial.print("Numero recebido: ");
  Serial.println(msgComoNumero);
  delay(1000);
  //Serial.flush();
}

PubSubClient client(server, port, whenMessageReceived, ethClient);

boolean reconnect() {
  Serial.println("reconectando...");
  if (client.connect("arduino-matias", "tmdigras", "P5UZxfYbqz7r")) {
    Serial.println("conectado");
    // client.publish("vaga/1","hello world");
    client.subscribe("vaga/#");
  }
  return client.connected();
}

void setup() {
  pinMode(ledverde,OUTPUT);
  pinMode(ledamarelo,OUTPUT); 
  pinMode(ledvermelho,OUTPUT); 
  pinMode(botao,INPUT);
  Serial.begin(9600);
  
// verificar se conseguiu pegar endereço via DHCP
  
  if (!Ethernet.begin(mac)) {
    Serial.println("DHCP Failed");
  } else {
    Serial.println(Ethernet.localIP());
  }

// conexao com o MQTT
char* clientId = "arduino-matias";

  // Conectando com informações de cliente e senha criados através da interface
  // web do serviço
  char* username = "tmdigras";
  char* password = "P5UZxfYbqz7r";

  if (client.connect(clientId, username, password)) {
    Serial.println("Connected");

    // Envia uma mensagem para o tópico 'temperatura'
    // https://pubsubclient.knolleary.net/api.html#publish1
    client.publish("temperatura", "23");
    Serial.println("temperatura enviada");

    // Se inscreve nos tópicos para que mensagens futuras possam ser
    // processadas através da função de callback
    client.subscribe("lampada");
    client.subscribe("temperatura");
  } else {
    Serial.println("Failed to connect to MQTT server");
  }
  lastReconnectAttempt = 0;
}

void liga_farol() {
   digitalWrite(ledvermelho,HIGH);
   delay(5000);
   digitalWrite(ledvermelho,LOW);
   digitalWrite(ledamarelo,HIGH);
   delay(2000);
   digitalWrite(ledamarelo,LOW);
   digitalWrite(ledverde,HIGH);
   delay(7000);
   digitalWrite(ledverde,LOW);
 }

void desliga_farol(){  
  digitalWrite(ledverde,LOW);
  digitalWrite(ledamarelo,LOW);
  digitalWrite(ledvermelho,LOW);
  }
void loop() {
  // put your main code here, to run repeatedly:
estadobotao = digitalRead(botao);
delay(1000);
if (estadobotao == HIGH) {
      if (ultimoestadobotao == HIGH) {   
        liga_farol();
        ultimoestadobotao = LOW;
      }
     else  
      { 
        desliga_farol();
        ultimoestadobotao = HIGH;
      }
}

if (ultimoestadobotao == HIGH) {
      liga_farol();
  }
if (ultimoestadobotao == LOW) {
      desliga_farol();
  }
 
 if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      Serial.println("reconectando...");
      lastReconnectAttempt = now;

      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    client.loop();
  }

}
