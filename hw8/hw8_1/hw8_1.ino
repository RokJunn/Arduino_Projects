byte patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};
int digit_select_pin[] = {66, 67, 68, 69};
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};
int SEGMENT_DELAY = 5; 
unsigned long time_previous, time_current;
int digit1 = 0, digit2 = 0, digit3 = 0;
int button_state = 0;
int pin_button = 14;

void setup() {
  pinMode(pin_button, INPUT);
  for (int i = 0; i < 4; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
  time_previous = millis();
  Serial.begin(9600);
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)
  for (int i = 0; i < 4; i++) {
    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

// 4자리 7세그먼트 표시 장치에 3자리 숫자를 표시하는 함수
void show_4_digit(int number) {
  number = number % 1000; // 3자리로 제한
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  show_digit(2, hundreads);
  delay(SEGMENT_DELAY);
  show_digit(3, tens);
  delay(SEGMENT_DELAY);
  show_digit(4, ones);
  delay(SEGMENT_DELAY);
}

void loop() {
  if(digitalRead(pin_button)){
    button_state++;
    delay(200);
  }
  time_current = millis();
  if (time_current - time_previous >= 1000) { // 1초 경과
    time_previous = time_current;
    if(button_state%2==0){
      digit1++; // 초 증가
      if (digit1 == 10) { // 60초가 되면 분 증가
        digit1 = 0;
       digit2++;
      }
      if (digit2 == 10){
        digit2 = 0;
        digit3++;
      }
      if (digit3 == 10){
        digit3 = 0;
      }
    }
    else if(button_state%2==1){
      digit1--; // 초 증가
      if (digit1 < 0) { // 60초가 되면 분 증가
        digit1 = 9;
        digit2--;
     }
     if (digit2 < 0){
        digit2 = 9;
        digit3--;
     }
     if (digit3 < 0){
        digit3 = 9;
     }
    } 
  }
  show_4_digit(digit3*100 + digit2*10 + digit1); // 시간 표시를 위해 4자리 숫자로 만듦
  Serial.print(digit3*100 + digit2*10 + digit1);
  Serial.print("\t");
  Serial.println(button_state);
}
