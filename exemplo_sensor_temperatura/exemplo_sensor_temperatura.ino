
//Sensor de temperatura usando o LM35
 
const int LM35 = A0; // Define o pino que lera a saída do LM35
int ADClido = 0;
float temperatura; // Variável que armazenará a temperatura medida
 
//Função que será executada uma vez quando ligar ou resetar o Arduino
void setup() {
analogReference(INTERNAL); // Caso falte essa linha , a conta nao fica correta
Serial.begin(9600); // inicializa a comunicação serial
}
 
//Função que será executada continuamente
void loop() {
//temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
ADClido = analogRead(LM35);
temperatura = ADClido * 0.1075268817204301;
Serial.print("Temperatura: ");
Serial.println(temperatura);
delay(2000);
}

// MUITO CUIDADO COM O SENSOR , A PARTE RETA PRECISA FICA OPOSTA AOS FIOS, SENAO O SENSOR FICA MUITO QUENTE
