int Illuminace = 56;
int pins_LED[]={2, 3, 4, 5};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i], OUTPUT);
    digitalWrite(pins_LED[i], LOW);
  }
}

void loop() {
  int count = 0;
  int adc = analogRead(56);
  
  if( adc < 150 ) count = 0;
  else if (adc < 325 ) count = 1;
  else if (adc < 500 ) count = 2;
  else if (adc < 675 ) count = 3;
  else count = 4;

  for(int i =0; i<4; i++){
    if(i < count)
      digitalWrite(pins_LED[i], HIGH);
    else
      digitalWrite(pins_LED[i], LOW);  
  }
  Serial. println (String("count : ") + count);
  delay(1000);
} 
