int pin_button = 15;
int pin_LED[]={2,3,4,5};
boolean state_previous = false;
boolean state_current;
int change=0;
int state=0;

void setup(){
  Serial.begin(9600);
  pinMode(pin_button, INPUT);
  for(int i=0;i<4;i++){
    pinMode(pin_LED[i], OUTPUT);
  }
}

void loop(){
  if(change%2==0)
    state = (--state+4)%4;
  else
    state = (++state)%4;
  
  for(int i=0;i<4;i++){
    if(i==state){
      digitalWrite(pin_LED[i], HIGH);
    }else{
      digitalWrite(pin_LED[i], LOW);
    }
  }
  for(int i=0; i<500; i++){
    state_current = digitalRead(pin_button);
    if(state_previous == false && state_current == true){
      change++;
      state_previous=true;
      delay(200);
      break;
    }else{
    state_previous=false;
    delay(1);
    }
  }
  
  
  
  Serial.print(change);
  Serial.print(" ");
  Serial.println(state); 
}
