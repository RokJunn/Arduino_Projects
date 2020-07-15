#include <Servo.h>

Servo myServo;
int servoPin = 11;
int pin_button1 = 14;
int pin_button2 = 15;
int angle = 0;

void setup() {
  myServo.attach(servoPin); 
  myServo.write(0);
  pinMode(pin_button1, INPUT);
  pinMode(pin_button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pin_button1)){
    if (angle < 180){
      angle += 10;
      Serial.println(angle);
      delay(200);   
    }
  }
  if(digitalRead(pin_button2)){
    if (angle > 0) {
      angle -= 10;
      Serial.println(angle);
      delay(200);
    }
  }
  myServo.write(angle);
}
