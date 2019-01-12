#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int maxdoC=0; 
int mindoC=100;
int maxdoF=0;
int mindoF=212;
int scale = 1;
int button=8;

void setup() {
   lcd.begin(16, 2);
   //default = 5v hoac 3.3v; internal = 1.1v voi ATmega328 hoặc ATmega168 va 2.56v voi ATmega8
                              //INTERNAL1V1; INTERNAL2V56; EXTERNAL = muc dien ap toi da duoc cap vao chan AREF (0-5v)
   pinMode(button, INPUT);
   lcd.clear();
} 

void loop() {
   lcd.setCursor(0,0); 
   int sensor = analogRead(0); 
   int buttonState = digitalRead(button); 
   switch (buttonState) { 
     case HIGH:
       scale=-scale; 
       lcd.clear();
   }
   delay(250);
   switch (scale) {
     case 1:
      TinhDoC(sensor);
      break;
     case -1:
      TinhDoF(sensor);
   }
  }
void TinhDoC(int sensor) {
   lcd.setCursor(0,0);
   int NhietDo = (sensor * (5*1000)/1024); //=100/1024....190 / 1024 = 0.185546875
   lcd.print(NhietDo);
   lcd.write(B11011111);
   lcd.print("C ");
   if (NhietDo>maxdoC) {
      maxdoC=NhietDo;
   }
   if (NhietDo<mindoC) {
      mindoC=NhietDo;
   }
   lcd.setCursor(0,1);
   lcd.print("Max: ");
   lcd.print(maxdoC);
   lcd.write(B11011111);
   lcd.print("Min: ");
   lcd.print(mindoC);
   lcd.write(B11011111);
   lcd.print("C ");
}
void TinhDoF(int sensor) {
   lcd.setCursor(0,0);
   float NhietDo = (((sensor/10) * (5*1000)/1024) * 1.8)+32; //=100/1024....190 / 1024 = 0.185546875
   lcd.print(int(NhietDo));
   lcd.write(B11011111);
   lcd.print("F ");
   if (NhietDo>maxdoF) {
      maxdoF=NhietDo;
   }
   if (NhietDo<mindoF) {
      mindoF=NhietDo;
   }
   lcd.setCursor(0,1);
   lcd.print("Max: ");
   lcd.print(maxdoF);
   lcd.write(B11011111); 
   lcd.print("Min: =");
   lcd.print(mindoF);
   lcd.write(B11011111);
   lcd.print("F ");
} 
