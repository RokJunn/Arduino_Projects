void setup() {
  Serial.begin(9600);
  for (int i=2; i<6; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  digitalWrite(2, HIGH);
  
  for (int i=3; i<6; i++){
    digitalWrite(i, HIGH);
    delay(1000);
  }
  for (int i=5; i>2; i--){
    digitalWrite(i, LOW); 
    delay(1000);
  }
}
