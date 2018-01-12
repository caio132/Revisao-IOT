// exemplo da utilização do FOR

// declaração das variaveis
const int led = 13;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.println("Iniciando a serial ...");

for (int contador = 1; contador <= 50; contador++) 
{
   Serial.print("contador: ");
   Serial.println(contador); 
}

}

void loop() {



}

