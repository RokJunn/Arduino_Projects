#include <SoftwareSerial.h>
unsigned long time_previous, time_current;
int minutes = 0, seconds = 10;
int bluetooth_state = 0;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  time_current = millis();
    
  if (time_current - time_previous >= 1000) { // 1초 경과
    if (state == 0) {
      Serial1.print(minutes+String(":"));
      if(seconds < 10) 
        Serial1.println(String("0")+seconds);
      else 
        Serial1.println(seconds);
    }else if (state == 1) {
      while(1){
        Serial1.println("완료되었습니다.");
        delay(1000);
      }
    }
  
    time_previous = time_current;
    seconds--; // 초 증가
    
    if (minutes <= 0 && seconds <= 0){
      state = 1;
    } else {
      state = 0;
    }
    
    if (seconds <= 0) { // 60초가 되면 분 증가
      seconds = 59;
      minutes--;
    }
      
  }
}
