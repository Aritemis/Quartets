#include <Adafruit_CircuitPlayground.h>
#include "pitches.h"
#include <SoftwareSerial.h>

SoftwareSerial port(9, 10);
boolean toggle = false;
int p = 0;
int i = 0;
int j = 0;
int colorCounter = 0;
int k = 0;

int part1[] = 
{
NOTE_A5, NOTE_AS5, 0, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_D6, NOTE_C6,
NOTE_AS5, 0, NOTE_A5, NOTE_AS5, NOTE_C6, 0, NOTE_D6, NOTE_C6,
0, NOTE_AS5, NOTE_C6, 0, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6,
NOTE_AS5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_DS6,
NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, 0, NOTE_D6, 
NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, 0,
0, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, 0, 
NOTE_D6, NOTE_DS6, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_C6, 
NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, 
NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6, 
NOTE_C6, 0, NOTE_AS5, NOTE_C6, 0, NOTE_AS5, NOTE_C6, NOTE_D6,
NOTE_C6, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_A5, NOTE_A5,
NOTE_C6, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, 
NOTE_A5, NOTE_AS5, NOTE_C6, 0, 0, NOTE_D6, NOTE_C6, NOTE_C6,
NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_F6, NOTE_DS6, NOTE_D6, 
NOTE_C6, NOTE_AS6, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_C6, 0, NOTE_D6, 
NOTE_DS6, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_AS5,
NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_DS6,
NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_C6, 0, NOTE_AS5, NOTE_A5,
NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5,
NOTE_AS5, NOTE_AS5, NOTE_C6, 0, NOTE_DS6, NOTE_DS6, NOTE_D6, NOTE_C6, 
NOTE_AS5, NOTE_C6, NOTE_D6
};

int soloDur[] = {
100, 50, 50, 100, 50, 50, 50, 100,
50, 50, 100, 50, 50, 100, 100, 100,
100, 100, 100, 100, 50, 50, 100, 50,
100, 100, 50, 50, 50, 50, 100, 100,
50, 50, 100, 100, 100, 200, 100, 50, 
50, 50, 50, 100, 100, 100, 100, 100,
100, 100, 100, 100, 50, 50, 50, 50, 
50, 50, 100, 100, 100, 50, 50, 200, 
100, 100, 200, 100, 100, 100, 50, 50, 
50, 50, 100, 100, 50, 50, 50, 50,
100, 100, 100, 100, 100, 50, 50, 100,
50, 50, 50, 200, 50, 50, 50, 100,
100, 50, 50, 50, 50, 100, 100, 50, 
50, 50, 50, 100, 100, 50, 50, 100,
50, 50, 100, 100, 100, 100, 50, 50, 
50, 50, 50, 50, 100, 100, 100, 50, 
50, 100, 100, 100, 100, 100, 100, 100,
100, 100, 50, 50, 50, 50, 100, 100,
100, 100, 50, 50, 100, 100, 100, 100,
100, 100, 100, 50, 50, 50, 50, 50,
100, 50, 50, 100, 100, 200, 200, 100, 
100, 200, 400
};

int part2[] = 
{
0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, // measure 1
0, 0, NOTE_DS5, 0, NOTE_DS5, 0, NOTE_DS5, 0, // measure 2
NOTE_DS5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0, // measure 3
NOTE_D5, 0, NOTE_DS5, 0, NOTE_DS5, 0, NOTE_DS5, 0, // measure 4
NOTE_DS5, 0, NOTE_D5, 0, NOTE_D5, 0, 0, 0, // measure 5
NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, // only 5 counts, incomplete?
0, // 3 counts
// this last rest was reduced from 4 counts to add to measure 6
0, 0, 0, 0, 0, 0, 0, 0, // x1 8-count rest made into x8 1-count rests
// ==== Sweetly
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, // measure 8
NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, // measure 9
NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, // measure 10
NOTE_AS4, NOTE_DS5, // - 1/8
NOTE_G5,
NOTE_DS5, NOTE_AS4, // - 1/8
NOTE_G5, NOTE_F5, 0, 0, 0, // measure 11
0, // - 4 counts
0, // - 2 counts
NOTE_G5, NOTE_F5, // - 1/8
NOTE_F5, // measure 12
NOTE_DS5, NOTE_F5, // - 1/8
NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_AS5,
NOTE_A5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_F5, NOTE_G5, // x6 @ 1/8 - measure 13
NOTE_G5, NOTE_F5, 0,
NOTE_G5, NOTE_A5, // - 1/8
NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, // measure 14
NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_F5, NOTE_F5, 0, 0, 0, // measure 15
NOTE_D5, NOTE_C4, NOTE_D5, NOTE_DS5, // x4 @ 1/8
NOTE_F5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_F5, // measure 16
NOTE_F5, NOTE_G5, NOTE_G5, NOTE_AS5,
NOTE_G5, NOTE_F5, // 2 counts - measure 17
NOTE_F5, NOTE_DS5, // 2 counts
NOTE_D5, // 4 counts - measure 18
};

int altoDur[] = {
100, 100, 100, 100, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100,
400,
100, 100, 100, 100, 100, 100, 100, 100,
// ==== Sweetly
100, 100, 100, 100, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 100, 100,
50, 50, 100, 50, 50, 100, 100, 100, 100, 100, 
400, 200, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 50, 50,
50, 50, 50, 50, 100, 100, 100, 50, 50, 100, 100,
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 50, 50, 50, 50, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 200,
200, 200, 200,
400
};

int part3[] = 
{
0, NOTE_AS5, 0, NOTE_AS5, 0, NOTE_AS5, 0, NOTE_AS5,
0, 0, NOTE_G5, 0, NOTE_G5, 0, NOTE_G5, 0,
NOTE_FS5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
NOTE_F5, 0, NOTE_G5, 0, NOTE_G5, 0, NOTE_G5, 0,
NOTE_G5, 0, NOTE_F5, 0, NOTE_F5, 0, 0, 0,
NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, 0, 0,
0, 0, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_D5,
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_A5, NOTE_AS5, NOTE_AS5,
NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5,
NOTE_F5, NOTE_G5, NOTE_G5, NOTE_DS6, NOTE_C6, NOTE_AS5, NOTE_G5, NOTE_C6,
0, 0, 0, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_F6, 0,
NOTE_G5, NOTE_F6, NOTE_DS6, NOTE_G5, NOTE_AS5, NOTE_A5, NOTE_AS5
};

int sopranoDur[] = {
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 
// 36 for some reason, not sure why it isn't a multiple of 8?
50, 50, 100, 50, 50, 100, 200, 100,
100, 100, 100, 100, 100, 200, 200, 200,
200, 50, 50, 50, 50, 100, 100, 100,
100, 50, 50, 50, 50, 100, 100, 100,
100, 300, 50, 200, 100, 100, 100, 100,
100, 100, 400, 400, 400
};

int part4[] = 
{
  NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0,
  0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4,
  0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4,
  0, NOTE_C5, 0, NOTE_C5, 0, NOTE_C5, 0, NOTE_C5,
  0, NOTE_C5, 0, NOTE_C5, 0, NOTE_AS4, 0, NOTE_AS4,
  0, 0, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4,
  0,
  0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  // == == Sweetly
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, //200
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_A4, //200
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, //200
  NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, //200
  // == == Section B
  NOTE_F4, //400,
  NOTE_C5, NOTE_D5, //200
  NOTE_AS4, //400,
  NOTE_G4, NOTE_AS4, //200,
  NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, //50
  NOTE_G4, NOTE_AS4,
  NOTE_F5, NOTE_DS5, //50
  NOTE_DS5, 0, NOTE_F4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_F4, 
  0, 0, 0,
  NOTE_AS4, //200
  NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, //50
  NOTE_D5, //200
  NOTE_AS4, NOTE_A4, //50
  NOTE_AS4, NOTE_C5, //200
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_C5, NOTE_F4, //200
  NOTE_F4 //400
};

int tenorDur[] = {
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100,
100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
  // == == Sweetly
200, 200, 200, 200, 200, 200, 200, 200, 
200, 200, 200, 200, 200, 200, 200, 200, 
  // == == Section B
400, 200, 200, 
400, 200, 200,
50, 50, 50, 50, 100, 100, 50, 50, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 200, 100, 50, 50, 50, 50, // is this measure only 7 counts?
200, 50, 50, 200, 200, 100, 
100, 100, 100, 200, 200, 
400
};

int mod = 2;
int maxSize = 0;
int duration = 0;
int current = part3;
char next = 'n';

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
    if(p < 5) toggle = true;
    p = 1;
    next = 'b';
    duration = soloDur[i];
    maxSize = sizeof(part1);
    delay(4);
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
        if(p < 5) toggle = true;
        p = 2;
        next = 'c';
        duration = altoDur[i];
        maxSize = sizeof(part2);
        current = part2;
        delay(2);
      }
      if(input == 'c')
      {
        if(p < 5) toggle = true;
        p = 3;
        next = 'd';
        duration = sopranoDur[i];
        maxSize = sizeof(part3);
        current = part3;
        delay(1);
      }
      if(input == 'd')
      {
        if(p < 5) toggle = true;
        p = 4;
//        duration = tenorDur[i];
//        maxSize = sizeof(part4);
//        current = part4;
      }
    }
  }
  
  if (toggle) 
  {
    delay(70);
    port.write(next);
    playNote(mod, current, duration, maxSize);
    k++;
    if(k > 8)
    {
      k = 0;
    }
  }
}

