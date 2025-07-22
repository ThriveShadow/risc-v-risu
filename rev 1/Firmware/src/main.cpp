#include <Arduino.h>

void myTone(uint8_t pin, unsigned int frequency, unsigned long duration_ms) {
    pinMode(pin, OUTPUT);
    if (frequency < 30 || frequency > 5000) {
        digitalWrite(pin, LOW);
        delay(duration_ms);
        return;
    }

    unsigned long period_us = 1000000UL / frequency;
    unsigned long cycles = (duration_ms * 1000UL) / period_us;

    for (unsigned long i = 0; i < cycles; i++) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(period_us / 2);
        digitalWrite(pin, LOW);
        delayMicroseconds(period_us / 2);
    }

    digitalWrite(pin, LOW); // ensure pin is low after tone
}

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Db4 311
#define F4 349
#define G4 392
#define Gb4 415
#define Ab4 466
#define C5 523
#define Cb5 554
#define D4 294
#define E4 330
#define C4 262
#define A3 220
#define Ab3 233
#define A4 440

const int shiny[35][3] = {
 {Db4, 174, 0},
 {F4, 174, 0},
 {G4, 174, 0},
 {Gb4, 349, 0},
 {Db4, 349, 0},
 {Ab4, 349, 0},
 {Gb4, 174, 0},
 {G4, 349, 0},
 {Gb4, 174, 0},
 {Ab4, 174, 0},
 {C5, 785, 87},
 {Gb4, 349, 0},
 {Db4, 349, 0},
 {Ab4, 349, 0},
 {Gb4, 174, 0},
 {G4, 349, 0},
 {Gb4, 174, 0},
 {Ab4, 174, 0},
 {C5, 698, 0},
 {C5, 174, 0},
 {Cb5, 174, 0},
 {C5, 349, 0},
 {Gb4, 698, 0},
 {C5, 174, 0},
 {Cb5, 174, 0},
 {C5, 349, 0},
 {Gb4, 698, 0},
 {C5, 174, 0},
 {Cb5, 174, 0},
 {C5, 174, 174},
 {Gb4, 785, 610},
 {Gb4, 174, 0},
 {Ab4, 349, 0},
 {Gb4, 174, 0},
 {Gb4, 523, 0},
};

const int alice[22][3] = {
 {D4, 176, 1},
 {E4, 176, 1},
 {F4, 352, 1},
 {F4, 352, 1},
 {C4, 352, 1},
 {C4, 352, 1},
 {G4, 529, 1},
 {F4, 176, 1},
 {G4, 352, 1},
 {F4, 352, 1},
 {E4, 353, 0},
 {D4, 705, 1},
 {A3, 352, 1},
 {Ab3, 352, 1},
 {F4, 706, 0},
 {E4, 352, 1},
 {F4, 352, 1},
 {G4, 352, 1},
 {A4, 1411, 1},
};

const int harapan[][3] = {
  {349, 119, 0},
  {349, 103, 0},
  {349, 222, 0},
  {349, 222, 0},
  {0,    0,   1},
  {392, 222, 0},
  {440, 222, 0},
  {0,    0, 667},
  {392,  97, 0},
  {392, 125, 0},
  {392, 222, 0},
  {392, 222, 0},
  {440, 222, 0},
  {0,    0,   1},
  {349, 222, 0},
  {0,    0, 444},
  {262,  94, 0},
  {262, 128, 0},
  {0,    0,   1},
  {349, 119, 0},
  {349, 103, 0},
  {349, 222, 0},
  {349, 222, 0},
  {392, 222, 0},
  {440, 222, 0},
  {0,    0, 223},
  {523, 128, 0},
  {0,    0, 316},
  {392, 102, 0},
  {392, 121, 0},
  {392, 121, 0},
  {0,    0, 101},
  {392, 121, 0},
  {0,    0, 101},
  {440, 121, 0},
  {0,    0, 101},
  {349, 121, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
  for (size_t i = 0; i < len; i++) {
    int freq = notes[i][0];
    int duration = notes[i][1];
    int delayAfter = notes[i][2];

    if (freq > 0) myTone(pin, freq, duration);  // Call renamed function
    else delay(duration); // rest note, no tone

    delay(delayAfter);
  }
}

void setup() {
  pinMode(C1, OUTPUT);
  digitalWrite(C1, HIGH);
  int pin = C2; // Change this to your desired pin
  playMidi(pin, alice, ARRAY_LEN(alice));
  digitalWrite(C1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}
