long num1, num2, sum;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter 2 Integers to add");
  while(true){
    
    if(Serial.available() > 0){
      long num1 = Serial.parseInt();
      while(true){
        if(Serial.available() > 0){
          long num2 = Serial.parseInt();
          long sum = num1 + num2;
          Serial.print(num1);
          Serial.print(" + ");
          Serial.print(num2);
          Serial.print(" = ");
          Serial.println(sum);
          break;
        }
      }
      break;  
    }
  }  
}
