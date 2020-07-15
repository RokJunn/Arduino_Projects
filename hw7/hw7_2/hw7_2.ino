#include <pitches.h>
int vResistor = A0;
int speakerPin = 57;

int melody[]={
  0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 
};
int noteDuration = 4;

void setup() {
  Serial.begin(9600);
  pinMode(vResistor, INPUT);
}

void loop() {
  int adc = analogRead(vResistor);
  int note = ((adc * 8) / 1023);
  Serial.println(String("adc : ") + adc + String("note : ") + note);
  int noteLength = 1000/noteDuration;
  tone(speakerPin, melody[note], noteLength);
  delay(noteLength);
  noTone(speakerPin);
}
