int pin_LED1=2;
int pin_LED2=3;
unsigned long time_previous1, time_current1;
unsigned long time_previous2, time_current2;
unsigned long interval1 = 1000;
unsigned long interval2 = 1000;
boolean LED_state1 = false;
boolean LED_state2 = false;

void setup() {
  pinMode(A0, INPUT);
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  digitalWrite(pin_LED1, LED_state1);
  digitalWrite(pin_LED2, LED_state2);
  time_previous1 = millis();
  time_previous2 = millis();
}

void loop() {
  time_current1 = millis();
  time_current2 = millis(); 
  if(time_current1 - time_previous1 >= interval1){
    time_previous1 = time_current1;
    LED_state1 = !LED_state1;
    digitalWrite(pin_LED1, LED_state1);
  }
  if(time_current2 - time_previous2 >= interval2){
    time_previous2 = time_current2;
    LED_state2 = !LED_state2;
    digitalWrite(pin_LED2, LED_state2);
  }
  int adc = analogRead(A0);
  interval1 = map(adc, 0, 1023, 500, 1500);
  interval2 = map(adc, 1023, 0, 500, 1500);
}
