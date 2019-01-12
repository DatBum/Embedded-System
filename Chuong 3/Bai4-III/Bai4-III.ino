byte ledPin[] = {3, 5, 6, 9, 10, 11};
int chietap = 2;

void setup() {  
  Serial.begin(9600);
  for (int x=0; x<6; x++) {
    pinMode(ledPin[x],OUTPUT);
  }
  pinMode(chietap,INPUT);
}

void loop() {
    for (int x=0; x<6; x++) {
      analogWrite(ledPin[x],analogRead(chietap));
    }
    Serial.println(analogRead(chietap));
}
