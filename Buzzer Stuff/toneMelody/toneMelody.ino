#include "pitches.h"
#define REST 0

// Pin definitions
const int buzzerPin = 8;
const int buttonOnPin = 2;
const int buttonOffPin = 3;
const int song1Pin = 4;
const int song2Pin = 5;

// Melody control
bool playingMelody = false;
unsigned long previousToneMillis = 0;
double currentNoteDuration = 0;
int currentIndex = 0;

// Song selection
int selectedSong = 1;

// ===== Song format types =====
enum SongFormat { PAIR_FORMAT, DUAL_ARRAY_FORMAT };
SongFormat currentFormat;

// ===== SONG 1 (PAIR FORMAT) =====
double song1[] = {
  REST, 2.0, NOTE_G4, 0.5, NOTE_FS4, 0.5, NOTE_E4, 0.5, NOTE_E4, 0.5,
  NOTE_FS4, 2.0, REST, 2.0,
  REST, 1.5, NOTE_A3, 0.5,
  NOTE_G4, 0.5, NOTE_FS4, 0.5, NOTE_E4, 0.5, NOTE_E4, 1.0,
  NOTE_FS4, 1.5,
  NOTE_D4, 1.0, NOTE_E4, 0.5, NOTE_A3, 2.5,
  REST, 1.5, NOTE_A3, 0.5,
  NOTE_E4, 1.0, NOTE_FS4, 0.5, NOTE_G4, 1.5, NOTE_E4, 0.5, NOTE_CS4, 1.0,
  NOTE_D4, 1.5, NOTE_E4, 1.0, NOTE_A3, 0.5, NOTE_A3, 1.0,
  NOTE_FS4, 1.5, REST, 2.0,
  REST, 2.0, NOTE_G4, 0.5, NOTE_FS4, 0.5, NOTE_E4, 0.5, NOTE_E4, 0.5,
  NOTE_FS4, 2.0, REST, 2.0,
  REST, 1.0, REST, 0.5, NOTE_A3, 0.5, NOTE_G4, 0.5, NOTE_FS4, 0.5, NOTE_E4, 0.5, NOTE_E4, 1.5,
  NOTE_FS4, 0.5, NOTE_D4, 1.5, NOTE_E4, 0.5, NOTE_A3, 2.5,
  REST, 2.0,
  NOTE_E4, 1.0, NOTE_FS4, 0.5, NOTE_G4, 1.5, NOTE_E4, 0.5, NOTE_CS4, 1.5,
  NOTE_D4, 0.5, NOTE_E4, 1.0, NOTE_A3, 0.5, NOTE_D4, 0.5, NOTE_E4, 0.5,
  NOTE_F4, 0.5, NOTE_E4, 0.5, NOTE_D4, 0.5, NOTE_C4, 0.5, REST, 1.0, NOTE_A3, 0.5, NOTE_AS3, 0.5,
  NOTE_C4, 1.0, NOTE_F4, 1.0, NOTE_E4, 0.5, NOTE_D4, 0.5, NOTE_D4, 0.5, NOTE_C4, 0.5,
  NOTE_D4, 0.5, NOTE_C4, 0.5, NOTE_C4, 1.0, NOTE_C4, 1.0, NOTE_A3, 0.5, NOTE_AS3, 0.5,
  NOTE_C4, 1.0, NOTE_F4, 1.0, NOTE_G4, 0.5, NOTE_F4, 0.5, NOTE_E4, 0.5, NOTE_D4, 0.5,
  NOTE_D4, 0.5, NOTE_E4, 0.5, NOTE_F4, 1.0, NOTE_F4, 1.0, NOTE_G4, 0.5, NOTE_A4, 0.5,
  NOTE_AS4, 0.5, NOTE_AS4, 0.5, NOTE_A4, 1.0, NOTE_G4, 1.0, NOTE_F4, 0.5, NOTE_G4, 0.5,
  NOTE_A4, 0.5, NOTE_A4, 0.5, NOTE_G4, 1.0, NOTE_F4, 1.0, NOTE_D4, 0.5, NOTE_C4, 0.5,
  NOTE_D4, 0.5, NOTE_F4, 0.5, NOTE_F4, 0.5, NOTE_E4, 1.0, NOTE_E4, 0.5, NOTE_FS4, 0.5, NOTE_FS4, 1.5,
  REST, 2.0, NOTE_A4, 0.5, NOTE_A4, 0.5,
  NOTE_B4, 0.5, NOTE_A4, 0.5, NOTE_FS4, 0.5, NOTE_D4, 1.0, NOTE_E4, 0.5, NOTE_FS4, 0.5, NOTE_FS4, 1.5,
  REST, 1.5, NOTE_A4, 0.5, NOTE_A4, 0.5, NOTE_A4, 0.5,
  NOTE_B4, 0.5, NOTE_A4, 0.5, NOTE_FS4, 0.5, NOTE_D4, 1.0, NOTE_E4, 0.5, NOTE_FS4, 0.5, NOTE_FS4, 1.5,
  REST, 1.5, NOTE_G4, 0.5, NOTE_A4, 0.5, NOTE_A4, 1.5,
  REST, 1.5, NOTE_G4, 0.5, NOTE_FS4, 0.5, NOTE_FS4, 1.5,
  0.0, 0.0
};

// ===== SONG 2 (DUAL ARRAY FORMAT) =====
int melody2[] = {
  880, 932, 1396, 932, 1396, 0,
  1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0,
  1396, 932, 1396, 0,
  1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0,
  932, 1864, 1661, 1396, 1480, 1661, 1244, 1174, 0,
  1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 1046, 1046, 1046, 1108, 1244, 0
};

int duration2[] = {
  400, 400, 950, 450, 1050, 400,
  400, 400, 400, 400, 400, 400, 400, 400, 200,
  850, 450, 1050, 450,
  400, 400, 400, 400, 400, 400, 400, 400, 250,
  600, 600, 1100, 400, 400, 500, 600, 1000, 700,
  400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 450
};

int totalNotes2 = sizeof(melody2) / sizeof(melody2[0]);

// ====== Function to start playing ======
void startNote(int note, double duration) {
  currentNoteDuration = duration;
  if (note != REST) {
    tone(buzzerPin, note, currentNoteDuration);
  } else {
    noTone(buzzerPin);
  }
}

// ================== SETUP ==================
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
  pinMode(song1Pin, INPUT_PULLUP);
  pinMode(song2Pin, INPUT_PULLUP);

  Serial.begin(115200);
  selectedSong = 1;
  currentFormat = PAIR_FORMAT;
}

// ================== LOOP ==================
void loop() {
  // ===== SONG SELECTION =====
  if (digitalRead(song1Pin) == LOW) {
    selectedSong = 1;
    currentFormat = PAIR_FORMAT;
    Serial.println("Song 1 Selected");
    delay(200);
  }

  if (digitalRead(song2Pin) == LOW) {
    selectedSong = 2;
    currentFormat = DUAL_ARRAY_FORMAT;
    Serial.println("Song 2 Selected");
    delay(200);
  }

  // ===== START =====
  if (digitalRead(buttonOnPin) == LOW) {
    playingMelody = true;
    currentIndex = 0;
    previousToneMillis = millis();

    if (currentFormat == PAIR_FORMAT) {
      int note = (int)song1[currentIndex];
      double duration = 1600.0 * (song1[currentIndex + 1] / 4);
      startNote(note, duration);
    } else {
      int note = melody2[currentIndex];
      double duration = duration2[currentIndex];
      startNote(note, duration);
    }
  }

  // ===== STOP =====
  if (digitalRead(buttonOffPin) == LOW) {
    playingMelody = false;
    noTone(buzzerPin);
    Serial.println("Playback Stopped");
  }

  // ===== MELODY PLAYBACK =====
  if (playingMelody) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousToneMillis >= (unsigned long)(currentNoteDuration * 1.3)) {
      noTone(buzzerPin);

      if (currentFormat == PAIR_FORMAT) {
        currentIndex += 2;
        double nextNote = song1[currentIndex];
        double nextDuration = song1[currentIndex + 1];
        if (nextDuration > 0.0) {
          startNote((int)nextNote, 1600.0 * (nextDuration / 4));
          previousToneMillis = currentMillis;
        } else {
          playingMelody = false;
          Serial.println("Song 1 Finished");
        }
      } else {
        currentIndex++;
        if (currentIndex < totalNotes2) {
          startNote(melody2[currentIndex], duration2[currentIndex]);
          previousToneMillis = currentMillis;
        } else {
          playingMelody = false;
          Serial.println("Song 2 Finished");
        }
      }
    }
  }
}
