int led_arduino = 13;

void setup() {
  // put your setup code here, to run once:
  
pinMode(led_arduino,OUTPUT); 
}

void loop() {
    // put your main code here, to run repeatedly:

digitalWrite(led_arduino,HIGH);
delay(100);
digitalWrite(led_arduino,LOW);
delay(100);

}
