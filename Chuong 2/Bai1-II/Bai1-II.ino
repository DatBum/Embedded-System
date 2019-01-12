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
  digitalWrite(redLed, HIGH); 
  delay(5000);
   
  digitalWrite(yellowLed, HIGH);
  delay(2000);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  
  digitalWrite(greenLed, HIGH);
  delay(10000);
  digitalWrite(greenLed, LOW);
  
  digitalWrite(yellowLed, HIGH);
  delay(2000);
  digitalWrite(yellowLed, LOW);
}
