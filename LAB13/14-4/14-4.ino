int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;
int pin_button = 14;
int button_state = 1;
int speed = 0;

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  digitalWrite(Enable1, HIGH);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pin_button)){
    if (button_state < 3){
      button_state++;
      Serial.println(button_state);
      delay(200);   
    }
    else{
      button_state = 1;
      Serial.println(button_state);
      delay(200);
    }
  }

  if(button_state == 1)
    speed = 0;
  else if(button_state == 2)
    speed = 127;
  else
    speed = 255;    
  
  
  analogWrite(PWM1, speed);
}
