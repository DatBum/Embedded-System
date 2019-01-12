int redLed1 = 10;
int redLed2 = 9;
int yellowLed = 8;
int greenLed1 = 7;
int greenLed2 = 6;
int button = 3;
unsigned long changeTime = 0;

void setup() {  
  Serial.begin(9600);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  pinMode(greenLed2, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  digitalWrite(greenLed1, HIGH);
  digitalWrite(greenLed2, HIGH);
  int state = digitalRead(button);
  if (state == HIGH && (millis() - changeTime) > 5000) {
    digitalWrite(greenLed1, LOW);
    digitalWrite(greenLed2, LOW); 
  
    digitalWrite(yellowLed, HIGH);
    delay(800);
    
    digitalWrite(yellowLed, LOW); 
    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, HIGH);
    delay(5000);
     
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(800);
    
    digitalWrite(yellowLed, LOW); 
    digitalWrite(greenLed1, HIGH);
    digitalWrite(greenLed2, HIGH);
  }
}
