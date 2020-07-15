#include <LiquidCrystal.h>

LiquidCrystal lcd(44, 45, 46, 47, 48, 49);

byte user1[8] = {
  B00000, 
  B10000, 
  B00111, 
  B01000, 
  B01000, 
  B01000, 
  B00111, 
  B00000
};

void readTemperature (){
  int reading = analogRead(55);
  float voltage = reading *5.0/1024.0;
  float temp_C = voltage * 100;
  lcd.setCursor(0, 0);
  lcd.print("Temp : ");
  lcd.print(temp_C);
  lcd.write(byte(0));
  Serial.println(temp_C);
}

void readIlluminance(){
  int reading = analogRead(56);
  float voltage = reading *5.0 / 1024.0;
  lcd.setCursor(0, 1);
  lcd.print("Light : ");
  lcd.print(voltage);
}

void setup() {
  Serial.begin(9600);
  lcd.createChar(0, user1);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.clear();
  readTemperature();
  readIlluminance();
  delay(1000);
} 
