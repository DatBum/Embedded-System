int redLed = 8;
int yellowLed = 9;
int greenLed = 10;

void setup() {  
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  for (int x=0; x<3 ; x++) {
    digitalWrite(redLed, HIGH); 
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, HIGH);
    delay(150);
     
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    delay(100);
  }
  
  for (int x=0; x<3 ; x++) {
    digitalWrite(redLed, HIGH); 
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, HIGH);
    delay(800);
     
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    delay(500);
  }
  
  for (int x=0; x<3 ; x++) {
    digitalWrite(redLed, HIGH); 
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, HIGH);
    delay(150);
     
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    delay(100);
  }
  delay(5000);
}
