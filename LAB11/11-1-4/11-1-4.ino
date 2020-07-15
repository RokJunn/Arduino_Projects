int trigPin = 3;
int echoPin = 2;
int motionPin = 8;
int led1Pin = 11;
int led2Pin = 12;

int led1Bright;
int led2Bright;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 340 / 10000 / 2; 
  if (distance > 100) {
    led1Bright = 0;
  } else {
    led1Bright = map(distance, 100, 0, 0, 255);
  }
  Serial.println(String("Distance(cm): ") + distance);
  Serial.print("led1Bright : ");
  Serial.println(led1Bright);
  analogWrite(led1Pin, led1Bright);

  
  int motion = digitalRead(motionPin);
  if(motion == 1) {
    Serial.println("Motion detected");
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led2Pin, LOW);
  } 
  
  delay(500);
}
