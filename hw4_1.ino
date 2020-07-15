void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1;
  String str[5];

  for(int i=0; i<5; i++){
    while(true){
      if(state==1){
        Serial.print("Enter the ");
        Serial.print(i+1);
        Serial.print("th Word --> ");\
        state = 2;
      }
      if(Serial.available()){
        str[i] = Serial.readString();
        Serial.println(str[i]); //+ " [" + in_str.length()+"]");
        state=1;
        break;
      }
    }
  }
  Serial.println("After Sorting");
  for(int i=0; i<4; i++){
    for(int j=i+1; j<5; j++){
      int compare = str[i].compareTo(str[j]);
      if(compare>0){
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  for(int i=0; i<5; i++){
    Serial.println(str[i]);
  }
}
