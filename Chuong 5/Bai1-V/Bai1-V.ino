#include <TimerOne.h>
  int latchPin = 8; 
  int clockPin = 12; 
  int dataPin = 11; 
  byte frame = 0; // variable to store the current frame being displayed
  byte led[8][8] = { {0, 56, 92, 158, 158, 130, 68, 56}, 
                     {0, 56, 124, 186, 146, 130, 68, 56},
                     {0, 56, 116, 242, 242, 130, 68, 56},
                     {0, 56, 68, 226, 242, 226, 68, 56},
                     {0, 56, 68, 130, 242, 242, 116, 56},
                     {0, 56, 68, 130, 146, 186, 124, 56},
                     {0, 56, 68, 130, 158, 158, 92, 56},
                     {0, 56, 68, 142, 158, 142, 68, 56} };
void setup() {
   pinMode(latchPin, OUTPUT); // set the 3 digital pins to outputs
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
   Timer1.initialize(10000); // set a timer of length 10000 microseconds
   Timer1.attachInterrupt(screenUpdate); // attach the screenUpdate function
}
void loop() {
   for (int i=0; i<8; i++) { 
      for (int j=0; j<8; j++) { 
        led[i][j]= led[i][j] << 1 | led[i][j] >> 7; 
      }
   }
   frame++; 
   if (frame>7) { frame =0;} 
      delay(100); 
}
void screenUpdate() { 
   byte row = B10000000; 
   for (byte k = 0; k < 9; k++) {
      digitalWrite(latchPin, LOW); 
   shiftIt(~led[frame][k] ); 
   shiftIt(row); 
   
   digitalWrite(latchPin, HIGH);
   row = row >> 1; 
   }
}
void shiftIt(byte dataOut) {
   boolean pinState; 
   digitalWrite(dataPin, LOW);
   for (int i=0; i<8; i++) {
   digitalWrite(clockPin, LOW);
   if ( dataOut & (1<<i) ) {
      pinState = HIGH;
   }
   else {
      pinState = LOW;
   }
   digitalWrite(dataPin, pinState);
   digitalWrite(clockPin, HIGH);
   digitalWrite(dataPin, LOW);
   }
   digitalWrite(clockPin, LOW);
} 
