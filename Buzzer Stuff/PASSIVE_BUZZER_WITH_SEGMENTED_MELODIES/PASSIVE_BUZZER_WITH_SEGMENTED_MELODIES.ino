// Outer Buttons
const int buttonOnPin = 2;
const int buttonOffPin = 3;

// Inner Buttons
const int buttonNextPin = 4;
const int buttonPrevPin = 5;

// Buzzer
const int buzzerPin = 14;
const int buzzerPin2 = 15;
const int buzzerPin3 = 16;

// Single Digit Seven Segment Display
const int aSegPin = 7;
const int bSegPin = 8;
const int cSegPin = 9;
const int dSegPin = 10;
const int eSegPin = 11;
const int fSegPin = 12;
const int gSegPin = 13;

// ======================================================
// 7-SEGMENT DIGIT PATTERNS (for common cathode display)
// ======================================================
// Order: a, b, c, d, e, f, g
const byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

// Songs
// ======================================================
// SONG 1 — From The Start
// ======================================================

int s1p1[] = { 880, 932, 1396, 932, 1396, 0 };
int s1d1[] = { 400, 400, 950, 450, 1050, 400 };

int s1p2[] = { 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0 };
int s1d2[] = { 400, 400, 400, 400, 400, 400, 400, 400, 200 };

int s1p3[] = { 1396, 932, 1396, 0 };
int s1d3[] = { 850, 450, 1050, 450 };

int s1p4[] = { 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0 };
int s1d4[] = { 400, 400, 400, 400, 400, 400, 400, 400, 50 };

int s1p5[] = { 932, 1864, 1661, 1396, 1480, 1661, 1244, 1174, 0 };
int s1d5[] = { 600, 600, 1100, 400, 400, 500, 600, 1000, 700 };

int s1p6[] = { 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 1046, 1046, 1046, 1108, 1244, 0 };
int s1d6[] = { 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 450 };

int s1p7[] = { 880, 932, 1396, 932, 1396, 0 }; 
int s1d7[] = { 400, 400, 950, 450, 1050, 400 }; 

int s1p8[] = { 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0 }; 
int s1d8[] = { 400, 400, 400, 400, 400, 400, 400, 400, 200 }; 

int s1p9[] = { 1396, 932, 1396, 0 }; 
int s1d9[] = { 850, 450, 1050, 450 }; 

int s1p10[] = { 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0 }; 
int s1d10[] = { 400, 400, 400, 400, 400, 400, 400, 400, 50 }; 

int s1p11[] = { 932, 1864, 1661, 1396, 1480, 1661, 1244, 1174, 0 }; 
int s1d11[] = { 600, 600, 1100, 400, 400, 500, 600, 1000, 700 }; 

int s1p12[] = { 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 1046, 1046, 1046, 1108, 1244, 0 }; 
int s1d12[] = { 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 450 }; 

int *melodyParts1[] = { s1p1, s1p2, s1p3, s1p4, s1p5, s1p6, s1p7, s1p8, s1p9, s1p10, s1p11, s1p12 };
int *durationParts1[] = { s1d1, s1d2, s1d3, s1d4, s1d5, s1d6, s1d7, s1d8, s1d9, s1d10, s1d11, s1d12 };
int totalNotes1[] = { 
  sizeof(s1p1)/sizeof(s1p1[0]),
  sizeof(s1p2)/sizeof(s1p2[0]),
  sizeof(s1p3)/sizeof(s1p3[0]),
  sizeof(s1p4)/sizeof(s1p4[0]),
  sizeof(s1p5)/sizeof(s1p5[0]),
  sizeof(s1p6)/sizeof(s1p6[0]),
  sizeof(s1p7)/sizeof(s1p7[0]),
  sizeof(s1p8)/sizeof(s1p8[0]),
  sizeof(s1p9)/sizeof(s1p9[0]),
  sizeof(s1p10)/sizeof(s1p10[0]),
  sizeof(s1p11)/sizeof(s1p11[0]),
  sizeof(s1p12)/sizeof(s1p12[0])
};
int totalParts1 = sizeof(melodyParts1) / sizeof(melodyParts1[0]);

// ======================================================
// SONG 2 — Still ALive
// ======================================================
int s2p1[] = { 1568, 1480, 1318, 1318, 1480, 0 };
int s2d1[] = { 400, 400, 400, 400, 400, 1000 };

int s2p2[] = { 880, 1568, 1480, 1318, 1318, 1480, 1174, 1318, 880, 0 };
int s2d2[] = { 400, 400, 400, 400, 1000, 400, 1000, 400, 200 };

int *melodyParts2[] = { s2p1, s2p2 };
int *durationParts2[] = { s2d1, s2d2 };
int totalNotes2[] = {
  sizeof(s2p1)/sizeof(s2p1[0]),
  sizeof(s2p2)/sizeof(s2p2[0])
};
int totalParts2 = sizeof(melodyParts2) / sizeof(melodyParts2[0]);

// ======================================================
// SONG 3 — Bad Piggies
// ======================================================
int s3p1[] = { 1046, 1046, 932, 1046, 932, 830, 783, 932, 830, 783, 698, 622, 698, 783, 0 };
int s3d1[] = { 600, 600, 200, 400, 600, 600, 600, 200, 200, 200, 200, 200, 200, 200, 1000 };

int s3p2[] = {  };
int s3d2[] = {  };

int *melodyParts3[] = { s3p1, s3p2 };
int *durationParts3[] = { s3d1, s3d2 };
int totalNotes3[] = {
  sizeof(s3p1)/sizeof(s3p1[0]),
  sizeof(s3p2)/sizeof(s3p2[0])
};
int totalParts3 = sizeof(melodyParts3) / sizeof(melodyParts3[0]);

// ======================================================
// SONG 4 — Golden Hour
// ======================================================
int s4p1[] = { 739, 830, 987, 1108 };
int s4d1[] = { 400, 400, 400, 400 };

int s4p2[] = {  };
int s4d2[] = {  };

int *melodyParts4[] = { s4p1, s4p2 };
int *durationParts4[] = { s4d1, s4d2 };
int totalNotes4[] = {
  sizeof(s4p1)/sizeof(s4p1[0]),
  sizeof(s4p2)/sizeof(s4p2[0])
};
int totalParts4 = sizeof(melodyParts4) / sizeof(melodyParts4[0]);

// ======================================================
// SONG 5 — Die With A Smile
// ======================================================
int s5p1[] = {  };
int s5d1[] = {  };

int s5p2[] = {  };
int s5d2[] = {  };

int *melodyParts5[] = { s5p1, s5p2 };
int *durationParts5[] = { s5d1, s5d2 };
int totalNotes5[] = {
  sizeof(s5p1)/sizeof(s5p1[0]),
  sizeof(s5p2)/sizeof(s5p2[0])
};
int totalParts5 = sizeof(melodyParts5) / sizeof(melodyParts5[0]);

// ======================================================
// SONG 6 — Passing Through
// ======================================================
int s6p1[] = {  };
int s6d1[] = {  };

int s6p2[] = {  };
int s6d2[] = {  };

int *melodyParts6[] = { s6p1, s6p2 };
int *durationParts6[] = { s6d1, s6d2 };
int totalNotes6[] = {
  sizeof(s6p1)/sizeof(s6p1[0]),
  sizeof(s6p2)/sizeof(s6p2[0])
};
int totalParts6 = sizeof(melodyParts6) / sizeof(melodyParts6[0]);

// ======================================================
// SONG 7 — 
// ======================================================
int s7p1[] = {  };
int s7d1[] = {  };

int s7p2[] = {  };
int s7d2[] = {  };

int *melodyParts7[] = { s7p1, s7p2 };
int *durationParts7[] = { s7d1, s7d2 };
int totalNotes7[] = {
  sizeof(s7p1)/sizeof(s7p1[0]),
  sizeof(s7p2)/sizeof(s7p2[0])
};
int totalParts7 = sizeof(melodyParts7) / sizeof(melodyParts7[0]);

// ======================================================
// SONG 8 — 
// ======================================================
int s8p1[] = {  };
int s8d1[] = {  };

int s8p2[] = {  };
int s8d2[] = {  };

int *melodyParts8[] = { s8p1, s8p2 };
int *durationParts8[] = { s8d1, s8d2 };
int totalNotes8[] = {
  sizeof(s8p1)/sizeof(s8p1[0]),
  sizeof(s8p2)/sizeof(s8p2[0])
};
int totalParts8 = sizeof(melodyParts8) / sizeof(melodyParts8[0]);

// ======================================================
// SONG 9 — 
// ======================================================
int s9p1[] = {  };
int s9d1[] = {  };

int s9p2[] = {  };
int s9d2[] = {  };

int *melodyParts9[] = { s9p1, s9p2 };
int *durationParts9[] = { s9d1, s9d2 };
int totalNotes9[] = {
  sizeof(s9p1)/sizeof(s9p1[0]),
  sizeof(s9p2)/sizeof(s9p2[0])
};
int totalParts9 = sizeof(melodyParts9) / sizeof(melodyParts9[0]);

// ======================================================
// SONG INDEXING SYSTEM
// ======================================================
struct Song {
  int **melodyParts;
  int **durationParts;
  int *totalNotes;
  int totalParts;
};

Song songs[] = {
  { melodyParts1, durationParts1, totalNotes1, totalParts1 },
  { melodyParts2, durationParts2, totalNotes2, totalParts2 },
  { melodyParts3, durationParts3, totalNotes3, totalParts3 },
  { melodyParts4, durationParts4, totalNotes4, totalParts4 },
  { melodyParts5, durationParts5, totalNotes5, totalParts5 },
  { melodyParts6, durationParts6, totalNotes6, totalParts6 },
  { melodyParts7, durationParts7, totalNotes7, totalParts7 },
  { melodyParts8, durationParts8, totalNotes8, totalParts8 },
  { melodyParts9, durationParts9, totalNotes9, totalParts9 }
};

int totalSongs = sizeof(songs) / sizeof(songs[0]);

// ======================================================
// NUMBER DISPLAY
// ======================================================
void displayDigit(int num) {
  if (num < 0 || num > 9) return; // safety check

  int segmentPins[] = {aSegPin, bSegPin, cSegPin, dSegPin, eSegPin, fSegPin, gSegPin};
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

// ======================================================
// CLEAR DISPLAY
// ======================================================
void clearDisplay() {
  int segmentPins[] = {aSegPin, bSegPin, cSegPin, dSegPin, eSegPin, fSegPin, gSegPin};
  for (int i = 0; i < 7; i++) digitalWrite(segmentPins[i], LOW);
}

// ======================================================
// CONTROL VARIABLES
// ======================================================
bool playingMelody = false;
int currentSong = 0;
int currentPart = 0;
int currentNote = 0;
unsigned long previousToneMillis = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);

  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);

  pinMode(buttonNextPin, INPUT_PULLUP);
  pinMode(buttonPrevPin, INPUT_PULLUP);

  pinMode(aSegPin, OUTPUT);
  pinMode(bSegPin, OUTPUT);
  pinMode(cSegPin, OUTPUT);
  pinMode(dSegPin, OUTPUT);
  pinMode(eSegPin, OUTPUT);
  pinMode(fSegPin, OUTPUT);
  pinMode(gSegPin, OUTPUT);

  Serial.begin(115200);

  displayDigit(currentSong + 1);
}

void loop() {
  // START
  if (digitalRead(buttonOnPin) == LOW) {
    startSong();
    delay(200);
  }

  // STOP
  if (digitalRead(buttonOffPin) == LOW) {
    stopSong();
    delay(200);
  }

  // NEXT SONG
  if (digitalRead(buttonNextPin) == LOW) {
    currentSong++;
    if (currentSong >= totalSongs) currentSong = 0;
    displayDigit(currentSong + 1);
    Serial.print("Switched to song: ");
    Serial.println(currentSong);
    delay(300);
  }

  // PREVIOUS SONG
  if (digitalRead(buttonPrevPin) == LOW) {
    currentSong--;
    if (currentSong < 0) currentSong = totalSongs - 1;
    displayDigit(currentSong + 1);
    Serial.print("Switched to song: ");
    Serial.println(currentSong);
    delay(300);
  }

  // MELODY PLAYBACK
  if (playingMelody) {
    unsigned long currentMillis = millis();
    Song &song = songs[currentSong];

    if (currentMillis - previousToneMillis >= song.durationParts[currentPart][currentNote]) {
      noTone(buzzerPin);
      currentNote++;

      if (currentNote < song.totalNotes[currentPart]) {
        tone(buzzerPin, song.melodyParts[currentPart][currentNote]);
        previousToneMillis = currentMillis;
      } else {
        currentPart++;
        if (currentPart < song.totalParts) {
          currentNote = 0;
          previousToneMillis = currentMillis;
          tone(buzzerPin, song.melodyParts[currentPart][currentNote]);
        } else {
          stopSong();
        }
      }
    }
  }
}

// ======================================================
// FUNCTIONS
// ======================================================
void startSong() {
  Song &song = songs[currentSong];
  if (song.totalParts == 0 || song.totalNotes[0] == 0) {
    Serial.println("No notes in this song.");
    return;
  }

  currentPart = 0;
  currentNote = 0;
  playingMelody = true;
  tone(buzzerPin, songs[currentSong].melodyParts[currentPart][currentNote]);
  previousToneMillis = millis();
  Serial.print("Playing song: ");
  Serial.println(currentSong);
}

void stopSong() {
  playingMelody = false;
  noTone(buzzerPin);
  //clearDisplay();
  Serial.println("Stopped song");
}
