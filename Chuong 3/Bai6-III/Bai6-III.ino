byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {  
  Serial.begin(9600);
  for (int x=0; x<10; x++) {
    pinMode(ledPin[x],OUTPUT);
  }
}

void loop() {
  for (int x=0; x<5; x++) {
    digitalWrite(ledPin[x],HIGH);
    delay(500-x*100);
  }
  for (int x=5; x<10; x++) {
    digitalWrite(ledPin[x],HIGH);
    delay((x-4)*100);
  }
  for (int x=9; x>=5; x--) {
    digitalWrite(ledPin[x],LOW);
    delay((x-4)*100);
  }
  for (int x=4; x>=0; x--) {
    digitalWrite(ledPin[x],LOW);
    delay(500-x*100);
  }
}
