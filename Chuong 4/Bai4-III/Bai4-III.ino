byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int chietap = A2;

void setup() {  
  Serial.begin(9600);
  for (int x=0; x<10; x++) {
    pinMode(ledPin[x],OUTPUT);
  }
  pinMode(chietap,INPUT);
}

void loop() {
  Serial.println(analogRead(chietap));

    Serial.println(analogRead(chietap)); 
    for (int x=0; x<10; x++) {
      digitalWrite(ledPin[x],HIGH);
      delay(analogRead(chietap)/5);
      Serial.println(analogRead(chietap)); 
    }
    for (int x=9; x>=0; x--) {
      digitalWrite(ledPin[x],LOW);     
      delay(analogRead(chietap)/5);
    }
  
}
