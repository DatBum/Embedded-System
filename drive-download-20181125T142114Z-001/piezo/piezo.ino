#include "pitches.h"
#define ACTIVATED LOW


const int PIEZO = 11;   //  Phase transition/transfer pin


void setup()
{
  Serial.begin(9600);
  pinMode("A5", INPUT);
  
  
}


// notes in the melody:
int melody[] = {
  NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
  NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4,
  NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,


  NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
  NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5,
  4.5, 2.25, 4.5, 2.25, 1.125, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25,
  4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2,
  4.5, 4.5, 4.5, 2.25, 4.5, 4.5,

  4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5,
  4.5, 2.25, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 3, 3, 4.5,
  2.25, 4.5, 2.25, 4.5, 2.25,
  4.5, 4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25,

} ;


void loop()
{
    for (int thisNote=0; thisNote <85; thisNote++) {
      int gtquangtro = analogRead(A5);
      int noteDuration = 600 / noteDurations[thisNote];
      tone(11, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.50;
      delay(gtquangtro*2);
      noTone(11);

  }

  noTone(PIEZO);


}
