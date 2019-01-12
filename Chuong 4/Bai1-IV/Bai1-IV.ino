int redPin = 13;
int bluePin = 12;
int greenPin = 11;
char buffer[18]; 

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void setLED(char *parameter){
  	int ledPin;
  	if(parameter[0] == 'R') ledPin = redPin;
  	else if(parameter[0] == 'B') ledPin = bluePin;
  	else if(parameter[0] == 'G') ledPin = greenPin;
  	int value = strtol(parameter+1, NULL, 10);
   	value = constrain(value,0,255);
   	analogWrite(ledPin, value); 
}
void splitString(char* str){
  Serial.println(str); 
  char* parameter;
  parameter = strtok(str, ",");
  while(parameter != NULL){
  	setLED(parameter);
    parameter = strtok(NULL, ",");
  }
  for (int x=0; x<16; x++) {
   	buffer[x]='\0';
  }
  Serial.flush(); 
}

void loop()
{
  if(Serial.available() > 0){
  	int index=0;
    delay(100);
    int numChar = Serial.available();
    if(numChar>15){
    	numChar=15;
    }
    while(numChar--){
    	buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}
