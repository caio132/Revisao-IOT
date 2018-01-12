#include <Servo.h>

Servo Servo1;

void setup() {
  // put your setup code here, to run once:
Servo1.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
Servo1.write(110);
delay(2000);
Servo1.write(30);
delay(2000);
}
