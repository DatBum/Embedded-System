#include <SPI.h>
#include <RFID.h>


#define SS_PIN 10
#define RST_PIN 9


RFID rfid(SS_PIN, RST_PIN);

// Setup variables:
int serNum0, serNum1, serNum2, serNum3, serNum4;
boolean a=LOW;

void setup()
{
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop()
{
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      if (rfid.serNum[0] != serNum0
          && rfid.serNum[1] != serNum1
          && rfid.serNum[2] != serNum2
          && rfid.serNum[3] != serNum3
          && rfid.serNum[4] != serNum4
         )
      {
        String x = "";
        x += String(rfid.serNum[0]);
        x += String(rfid.serNum[1]);
        x += String(rfid.serNum[2]);
        x += String(rfid.serNum[3]);
        x += String(rfid.serNum[4]);
        if(x=="22018980195242")
        {
          _blink();
          delay(200);
          _blink();
        }
        else
        {
           a=!a;
          digitalWrite(7,a);
          delay(200);

        }
        Serial.println(x);
      }
    }
  }
  rfid.halt();
}


void _blink()
{
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    delay(100);
}
