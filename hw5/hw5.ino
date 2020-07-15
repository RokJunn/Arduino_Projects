int pins_LED[]={2,3,4,5};
int PWM_value[4] = {0, 63, 127, 191};

void setup(){
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i], OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop(){
  for(int i=0; i<4; i++){
    analogWrite(pins_LED[i], PWM_value[i]);
    if (PWM_value[i] >= 255){
      PWM_value[i]=0;
    }
    PWM_value[i] += 10;
    Serial.print(" ");
    Serial.print(PWM_value[i]);
  }
  Serial.println();  
  delay(100);
}
