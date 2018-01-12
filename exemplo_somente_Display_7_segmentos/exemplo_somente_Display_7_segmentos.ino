
const int a = 9;
const int b = 6;
const int c = 7;
const int d = 8; 


void setup()
{
  //Define o número de colunas e linhas do LCD
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  
}
 
void loop()
{

  digitalWrite(a, LOW);//DIGITO 0
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, HIGH);//DIGITO 1
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, LOW);//DIGITO 2
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, HIGH);//DIGITO 3
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, LOW);//DIGITO 4
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, HIGH);//DIGITO 5
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, LOW);//DIGITO 6
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, HIGH);//DIGITO 7
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(1000);
      digitalWrite(a, LOW);//DIGITO 8
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      delay(1000);
      digitalWrite(a, HIGH); //DIGITO 9
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      delay(1000);
  
}
