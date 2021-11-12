/*
  Based on Tom Igoe's code
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

#define buzzerPin 2

// notes in the melody:
// use 0 for a rest
// put each measure on its own line
int melody[] = {
  NOTE_DS5, NOTE_E5, NOTE_B5, NOTE_GS5, NOTE_B5, NOTE_E5, NOTE_B5, 
  NOTE_GS5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_B5, NOTE_E5, NOTE_A5, 
  NOTE_C5, NOTE_E5, NOTE_B5, NOTE_C5, NOTE_B5, NOTE_C5, NOTE_E5, 
  NOTE_GS5, NOTE_C5, NOTE_E5, NOTE_E5
  
};

// note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
// be sure each note or rest in the melody above has a corresponding duration below
// put each measure on its own line
int noteDurations[] = {
  2, 4, 3, 4, 3, 3, 4, 
  2, 6, 4, 4,
  0.75, 1, 3, 4,
  2, 2, 2, 4, 2, 2, 4, 4, 4, 4
};

// set the tempo
// a tempo of 60 is one beat per second
// a tempo of 120 would be twice as fast
int beatsPerMinute = 70;

void setup() {

}

void loop() {
  // iterate over the notes of the melody:
  int len = sizeof(melody)/sizeof(melody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(10);
}
