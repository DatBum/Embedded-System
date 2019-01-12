int ledPins[] = {9, 10, 11};
int R = 9;
int G = 10;
int B = 11;
int pinCount = 3;
void setup() {
  Serial.begin(9600);
  Serial.flush();
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void splitString(char* str)
{
  int i = 0;
  while (str[i]) {
    String led = "";
    led += str[i++];
    while (str[i] > 47 && str[i] < 58) {
      led += str[i];
      i++;
    }
    char ledBuffer[led.length() + 1];
    led.toCharArray(ledBuffer, led.length() + 1);
    setLED(ledBuffer);
  }
}
void setLED(char* led) {
  String temp = "";
  for (int i = 1; i < strlen(led); i++) {
    temp += led[i];
  }
  int value = temp.toInt();
 
  switch (led[0]) {
    case 'R' :
      analogWrite(R, value);
      Serial.print("Red led value: ");
      Serial.println(value);
      break;
    case 'G' :
      analogWrite(G, value);
      Serial.print("Green led value: ");
      Serial.println(value);
      break;
    case 'B' :
      analogWrite(B, value);
      Serial.print("Blue led value: ");
      Serial.println(value);
      break;
    default :
      Serial.print("Wrong char detected: ");
      Serial.println(led[0]);
      if (led[1] > 47 && led[1] < 58)
        delay(value);
      Serial.print("Delay: ");  
      Serial.println(value);
  }
}

void loop() {
  if (Serial.available()) {
    int index = 0;
    delay(100);
    int numChar = Serial.available();
    String str = "";
    for (int i = 0; i < numChar; i++) {
      str += char(Serial.read());
    }
    
    Serial.println(str);
    char buffer[numChar];
    str.toCharArray(buffer, numChar);
    splitString(buffer);
  }
}
