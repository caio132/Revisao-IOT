// exemplo da utilização do WHILE

// declaração das variaveis
const int led = 13;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.println("Iniciando a serial ...");

int contador = 1;
while (contador <= 50)  {
   Serial.print("contador: ");
   Serial.println(contador); 
   contador++;
  }
}
void loop() {

}

