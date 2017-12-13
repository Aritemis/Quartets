#include <Adafruit_CircuitPlayground.h>
#include "pitches.h"
#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial port(9, 10);
boolean toggle = false;
int p = 0;
int i = 0;
int j = 0;
int colorCounter = 0;
int k = 0;

int part1[] = {
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 2
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 4
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 6
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 8
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 10
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 12
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 14
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 16
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 18
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 20
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 22
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 23
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 24
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, //measure 26
  0, NOTE_BS4, 0, NOTE_BS4, 0, NOTE_BS4, 0, NOTE_BS4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4
};

int part2[] = {
  0, 0, 0, 0, 0, 0, 0, 0, // measure 1
  0, 0, 0, 0, 0, 0, 
  NOTE_AS4, NOTE_AS5, NOTE_AS4, NOTE_AS5, // dur 1/16
  0, 0, 0, 0, 0, 0, 0, 0, // measure 3
  0, 0, 0, 0, 0, 0, 0, 0, // measure 4
  0, 0, 0, 0, 
  NOTE_AS4, NOTE_AS5, NOTE_AS4, NOTE_AS5, // dur 1/16
  0, 0, // measure 5
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_CS5, NOTE_DS5, 
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_DS5, NOTE_B4, 
  0, NOTE_A4, NOTE_C4, NOTE_GS4, NOTE_DS5, NOTE_GS4, NOTE_C5, NOTE_CS5, // measure 9
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_CS5, NOTE_DS5, 
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_C5, NOTE_CS5, 
  0, NOTE_GS5, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, 
  0, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_A4, // measure 13
  NOTE_AS6, // 3 counts
  NOTE_B5, 
  NOTE_G5, // 3 counts
  NOTE_G5, // measure 14
  NOTE_GS5, 
  NOTE_A6, // 4 counts
  NOTE_C5, 
  NOTE_AS4, 
  0, // measure 15 (inserted rest to complete measure)
  NOTE_CS5, // 3 counts
  NOTE_C5, 
  NOTE_AS4, // 3 counts
  NOTE_CS5, // measure 16
  NOTE_C5, // 4 counts
  0, 0, 0, NOTE_DS5, // measure 17
  NOTE_CS5, // 3 counts
  NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_CS5, // dur 1/16
  0, NOTE_DS5, 0, // added rest to complete measure 18
  NOTE_F5, 
  NOTE_DS5, // 3 counts
  NOTE_CS5, 
  NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, // dur 1/16
  NOTE_CS5, // 3 counts
  NOTE_C5, NOTE_AS4, 
  NOTE_AS4, NOTE_A4, NOTE_GS4, 0, // measure 20
  // {NOTE_AS4, NOTE_A4, NOTE_GS4} SPECIAL duration of 1/8 divided by 3
  // I modified the last 3 notes to add a rest and "complete" measure 20
  // by instead using each at 1/8 in part because 1/16 notes sound awful
  // and there's like, no point to making one even shorter; also timing?
  NOTE_G4, // 3 counts
  NOTE_A4, // 4 counts
  NOTE_AS4,
  // measure 21
  NOTE_C5, // 3 counts
  NOTE_CS5, 
  NOTE_C5, // 3 counts
  NOTE_CS5, 
  // measure 22
  NOTE_F5, NOTE_DS5, 
  NOTE_DS5, // 3 counts
  NOTE_DS5, NOTE_F5, // dur 1/16
  0, 0, // added 2 rests to complete measure 23
  NOTE_FS5, NOTE_F5, NOTE_DS5, 
  NOTE_CS5, NOTE_DS5, // dur 1/16
  0, 0, 0, 0, // added 4 rests to complete measure 24
  NOTE_C5, // 4 counts
  0, 0, 0, 
  NOTE_DS5, NOTE_F5, // dur 1/16 measure 25
  NOTE_FS5, // 3 counts
  NOTE_DS5, 
  NOTE_FS5, // 3 counts
  NOTE_A6, // measure 26
  NOTE_GS5, // 2 counts
  NOTE_FS5, // 4 counts
  0, 
  NOTE_FS5, NOTE_GS5, // dur 1/16 measure 27
  NOTE_FS2, // 2 counts
  NOTE_F5, // 2 counts
  NOTE_DS5, // 3 counts
  NOTE_F5, NOTE_DS5, // dur 1/16 measure 28
  NOTE_C5, // 2 counts
  NOTE_A4, // 2 counts
  0, 0, 0, 0 // added 4 rests to complete measure 29
  };

int part2dur[] = {
  42, 42, 42, 42, 42, 42, 42, 42, // measure 1
  42, 42, 42, 42, 42, 42, 21, 21, 21, 21, // measure 2
  42, 42, 42, 42, 42, 42, 42, 42, // measure 3
  42, 42, 42, 42, 42, 42, 42, 42, // measure 4
  42, 42, 42, 42, 21, 21, 21, 21, 42, 42, // measure 5
  42, 42, 42, 42, 42, 42, 42, 42, 
  42, 42, 42, 42, 42, 42, 42, 42, 
  42, 42, 42, 42, 42, 42, 42, 42, // "measure 9"
  42, 42, 42, 42, 42, 42, 42, 42, 
  42, 42, 42, 42, 42, 42, 42, 42, 
  42, 42, 42, 42, 42, 42, 42, 42, 
  42, 42, 42, 42, 42, 42, 42, 42, // "measure 13"
  125, 42, 125, 42, // measure 14
  42, 167, 42, 42, 42, // measure 15
  125, 42, 125, 42, // measure 16
  167, 42, 42, 42, 42, // measure 17
  125, 21, 21, 21, 21, 42, 42, 42, // measure 18
  42, 125, 42, 21, 21, 21, 21, 125, 42, 42, 42, 42, 42, 42, // measures 19 & 20
  125, 167, 42, // measure 21
  125, 42, 125, 42, // measure 22
  42, 42, 125, 21, 21, 42, 42, // measure 23
  42, 42, 42, 21, 21, 42, 42, 42, 42, // measure 24
  167, 42, 42, 42, 21, 21, // measure 25
  125, 42, 125, 42, // measure 26
  83, 167, 42, 21, 21, // measure 27
  83, 83, 125, 21, 21, // measure 28
  83, 83, 42, 42, 42, 42 // measure 29
  };

int part3[] = {
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16 
  NOTE_CS4, // measure 1 (8)
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16 @ 15 & 16
  NOTE_CS4, // measure 2 (17)
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16 @ 24 & 25
  NOTE_C4, // measure 3 (26)
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16 @ 33 & 34
  NOTE_C4, // measure 4 (35)
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16 @ 42 & 43
  NOTE_CS4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur1/16
  NOTE_C4, 
  NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_G3, NOTE_A3, NOTE_AS3, 
  NOTE_FS3, NOTE_GS3, // dur 1/16
  NOTE_AS3, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4, 
  NOTE_DS3, NOTE_F4, NOTE_AS4, NOTE_DS3, NOTE_F4, NOTE_FS4, 
  NOTE_DS3, NOTE_F4, // dur 1/16
  NOTE_AS4, 
  NOTE_CS4, NOTE_DS3, NOTE_F4, NOTE_CS4, NOTE_DS3, NOTE_F4, 
  NOTE_CS4, NOTE_DS3, // dur 1/16
  NOTE_F4, 
  NOTE_C4, NOTE_CS4, NOTE_DS3, NOTE_C4, NOTE_CS4, NOTE_DS3, 
  NOTE_C4, NOTE_CS4, // dur 1/16
  NOTE_DS3, 
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4, 
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4
  };

int part4[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 2
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 4
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 6
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 8
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, NOTE_G4, NOTE_FS4, // measure 10
  0, 0, 0, 0, 0, 0, NOTE_FS4, NOTE_F4, 
  0, 0, 0, 0, 0, 0, NOTE_F4, NOTE_FS4, // measure 12
  0, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_FS4, NOTE_FS4, NOTE_F4, 
  NOTE_AS4, //3 counts @104
  NOTE_BS4,
  NOTE_G4, //3 counts @106
  NOTE_G4, // measure 14
  NOTE_GS4, NOTE_A4, NOTE_A4, //4 counts @110
  0, 0, // measure 15 (112)
  0, 0, 0, 0, 0, 0, 0, 0, // measure 16 (120)
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 18 (136)
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 20 (152)
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 22 (168)
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, // measure 24 (184)
  0, 0, 0, 0, 0, 0, 0, 0, // measure 25 (192)
  0, 0, 
  NOTE_AS4, //2 counts @195
  NOTE_AS4, //4 counts @196 -- measure 26
  0, 0, 
  NOTE_FS4, //4 counts @199
  0, 0, 
  0, 0, 
  NOTE_FS4, //4 counts @204
  0, 0, 
  NOTE_F4, //4 counts @207
  NOTE_DS4, //2 counts @208
  NOTE_C4 //2 counts @209
};

void setup() 
{
  CircuitPlayground.begin();
  Serial.begin(9600);
  port.begin(9600);
}

void loop() 
{
  if(CircuitPlayground.rightButton()) 
  {
    if (toggle) toggle = false;
    else toggle = true;
    p = 1;
    port.write('b');
    delay(250);
  }

  if(p == 0)
  {
    port.listen();
    if(port.peek() == -1)
    {
    
    }
    else
    {
      char input = port.read();
      if(input == 'b')
      {
        toggle = true;
        p = 2;
        port.write('c');
        delay(250);
      }
      if(input == 'c')
      {
        toggle = true;
        p = 3;
        port.write('d');
        delay(250);
      }
      if(input == 'd')
      {
        toggle = true;
        p = 4;
        delay(250);
      }
    }
  }
  
  if (toggle) 
  {
    delay(250);
    if(p == 1)
    {
      port.write('b');
      int maxSize = sizeof(part1);
      playNote(2, part1, 42, maxSize);
    }
    else if(p == 2)
    {
      port.write('c');
      int duration = part2dur[i];
      int maxSize = sizeof(part2);
      playNote(2, part2, duration, maxSize);
    }
    else if(p == 3)
    {
      port.write('d');
      int duration = 42;
      int maxSize = sizeof(part3);
      if (k == 6 || k == 7) duration = 21;
//      playNote(2, part3, duration, maxSize);
      k++;
    }
    else if(p == 4)
    {
      int duration = 42;
      if (i == 195 || i == 208 || i == 209) duration = 83; // 2 counts
      else if (i == 104 || i == 106) duration = 125; // 3 counts
      else if (i == 110 || i == 196 || i == 199 || i == 204 || 207) duration = 167; // 4 counts
      int maxSize = sizeof(part4);
//      playNote(2, part4, duration, maxSize);
    }
  }
}

void playNote(int mod, int current[], int noteDuration, int maxSize) 
{
  noteDuration *= mod;
  CircuitPlayground.playTone(current[i], noteDuration);
  if (i < maxSize) i++;
  else
  {
    toggle = false;
    i = 0;
    p = 5;
  }
  CircuitPlayground.setPixelColor(random(0,9), random(0,255), random(0,255), random(0,255));
  if (j < 10) j++;
  else j = 0;
  delay(100);
  CircuitPlayground.setPixelColor(j-1, 0, 0, 0);
}

