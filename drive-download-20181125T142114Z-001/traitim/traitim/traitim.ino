// Project 19 
#include <TimerOne.h> // Install the library first or the code won’t work  
int latchPin = 8;     //Pin connected to Pin 12 of 74HC595 (Latch) 
int clockPin = 12;    //Pin connected to Pin 11 of 74HC595 (Clock) 
int dataPin = 11;     //Pin connected to Pin 14 of 74HC595 (Data)  
byte led[8];          // 8 element unsigned integer array to hold the sprite  
void setup() {  // set the 3 digital pins to outputs  
  pinMode(latchPin, OUTPUT);  pinMode(clockPin, OUTPUT);  
  pinMode(dataPin, OUTPUT);     // Load the binary representation of the image into the array  
  led[0] = B01000100;  
  led[1] = B11101110;  
  led[2] = B11111110;  
  led[3] = B11111110;  
  led[4] = B11111110;  
  led[5] = B01111100;  
  led[6] = B00111000;  
  led[7] = B00010000;     // set a timer of length 10000 microseconds (1/100th of a second)  // and attach the screenUpdate function to the interrupt timer  
  Timer1.initialize(10000);  
  Timer1.attachInterrupt(screenUpdate); 
  } 
  
void loop() {   
  for (int i=0; i<8; i++) {    
    led[i]= ~led[i];  
    }  
    delay (250); 
    }  // Display the image 
    void screenUpdate() { 
      byte row = B10000000; // row 1 
      for (byte k = 0; k < 8; k++) {        
        shiftOut(dataPin, clockPin, LSBFIRST, led[k] ); // LED array      
        shiftOut(dataPin, clockPin, LSBFIRST, ~row);    // row binary number (active low)        // latch low to high to output data      
        digitalWrite(latchPin, LOW);      
        digitalWrite(latchPin, HIGH);
      
      // bitshift right      
      row = row >> 1;
      }
 
// Turn all rows off until next interrupt      
shiftOut(dataPin, clockPin, LSBFIRST, 0);      
shiftOut(dataPin, clockPin, LSBFIRST, ~0);        // latch low to high to output data      
digitalWrite(latchPin, LOW);      
digitalWrite(latchPin, HIGH); 
}
