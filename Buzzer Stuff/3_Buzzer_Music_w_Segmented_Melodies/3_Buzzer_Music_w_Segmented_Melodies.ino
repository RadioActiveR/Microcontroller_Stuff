// Outer Buttons
const int buttonOnPin = 2;
const int buttonOffPin = 3;

// Inner Buttons
const int buttonNextPin = 4;
const int buttonPrevPin = 5;

// Buzzers (3-channel polyphony)
const int buzzerPin  = 14;
const int buzzerPin2 = 15;
const int buzzerPin3 = 16;

// ESP32 PWM Channels
const int ch1 = 0;
const int ch2 = 1;
const int ch3 = 2;

// Single Digit Seven Segment Display
const int aSegPin = 7;
const int bSegPin = 8;
const int cSegPin = 9;
const int dSegPin = 10;
const int eSegPin = 11;
const int fSegPin = 12;
const int gSegPin = 13;

// ======================================================
// 7-SEGMENT DIGIT PATTERNS
// ======================================================
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

// ======================================================
// SONG DATA (unchanged from your code)
// ======================================================

// --- SONG 1 ---
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

int *melodyParts1[] = { s1p1, s1p2, s1p3, s1p4, s1p5, s1p6 };
int *durationParts1[] = { s1d1, s1d2, s1d3, s1d4, s1d5, s1d6 };
int totalNotes1[] = {
  sizeof(s1p1)/4, sizeof(s1p2)/4, sizeof(s1p3)/4,
  sizeof(s1p4)/4, sizeof(s1p5)/4, sizeof(s1p6)/4
};
int totalParts1 = 6;

// --- SONG 2 ---
int s2p1[] = { 1568, 1480, 1318, 1318, 1480, 0 };
int s2d1[] = { 400, 400, 400, 400, 400, 1000 };

int s2p2[] = { 880, 1568, 1480, 1318, 1318, 1480, 1174, 1318, 880, 0 };
int s2d2[] = { 400, 400, 400, 400, 1000, 400, 1000, 400, 200 };

int *melodyParts2[] = { s2p1, s2p2 };
int *durationParts2[] = { s2d1, s2d2 };
int totalNotes2[] = { sizeof(s2p1)/4, sizeof(s2p2)/4 };
int totalParts2 = 2;

// --- Empty SONGS 3–9 kept for indexing ---
int emptyP[] = {};
int emptyD[] = {};

int *melodyParts3[] = { emptyP, emptyP };
int *durationParts3[] = { emptyD, emptyD };
int totalNotes3[] = { 0, 0 };
int totalParts3 = 2;

int *melodyParts4[] = { emptyP, emptyP };
int *durationParts4[] = { emptyD, emptyD };
int totalNotes4[] = { 0, 0 };
int totalParts4 = 2;

int *melodyParts5[] = { emptyP, emptyP };
int *durationParts5[] = { emptyD, emptyD };
int totalNotes5[] = { 0, 0 };
int totalParts5 = 2;

int *melodyParts6[] = { emptyP, emptyP };
int *durationParts6[] = { emptyD, emptyD };
int totalNotes6[] = { 0, 0 };
int totalParts6 = 2;

int *melodyParts7[] = { emptyP, emptyP };
int *durationParts7[] = { emptyD, emptyD };
int totalNotes7[] = { 0, 0 };
int totalParts7 = 2;

int *melodyParts8[] = { emptyP, emptyP };
int *durationParts8[] = { emptyD, emptyD };
int totalNotes8[] = { 0, 0 };
int totalParts8 = 2;

int *melodyParts9[] = { emptyP, emptyP };
int *durationParts9[] = { emptyD, emptyD };
int totalNotes9[] = { 0, 0 };
int totalParts9 = 2;

// ======================================================
// SONG INDEX STRUCTURE
// ======================================================
struct Song {
  int **melodyParts;
  int **durationParts;
  int *totalNotes;
  int totalParts;
};

Song songs[] = {
  {melodyParts1, durationParts1, totalNotes1, totalParts1},
  {melodyParts2, durationParts2, totalNotes2, totalParts2},
  {melodyParts3, durationParts3, totalNotes3, totalParts3},
  {melodyParts4, durationParts4, totalNotes4, totalParts4},
  {melodyParts5, durationParts5, totalNotes5, totalParts5},
  {melodyParts6, durationParts6, totalNotes6, totalParts6},
  {melodyParts7, durationParts7, totalNotes7, totalParts7},
  {melodyParts8, durationParts8, totalNotes8, totalParts8},
  {melodyParts9, durationParts9, totalNotes9, totalParts9}
};

int totalSongs = 9;

// ======================================================
// DISPLAY
// ======================================================
void displayDigit(int num){
  int segs[] = {aSegPin,bSegPin,cSegPin,dSegPin,eSegPin,fSegPin,gSegPin};
  for(int i=0;i<7;i++) digitalWrite(segs[i], digits[num][i]);
}

// ======================================================
// ESP32 TONE REPLACEMENT
// ======================================================
void playFreq(int channel, int freq){
  if(freq > 0) ledcWriteTone(channel, freq);
  else ledcWrite(channel, 0); // silent
}

void stopAll(){
  ledcWrite(ch1, 0);
  ledcWrite(ch2, 0);
  ledcWrite(ch3, 0);
}

// ======================================================
// CONTROL VARIABLES
// ======================================================
bool playingMelody = false;
int currentSong = 0;
int currentPart = 0;
int currentNote = 0;
unsigned long previousMillis = 0;

void setup(){
  Serial.begin(115200);

  // PWM setup
  ledcSetup(ch1, 2000, 10);
  ledcAttachPin(buzzerPin, ch1);

  ledcSetup(ch2, 2000, 10);
  ledcAttachPin(buzzerPin2, ch2);

  ledcSetup(ch3, 2000, 10);
  ledcAttachPin(buzzerPin3, ch3);

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

  displayDigit(1);
}

void loop(){
  if(digitalRead(buttonOnPin)==LOW){
    startSong();
    delay(200);
  }

  if(digitalRead(buttonOffPin)==LOW){
    stopSong();
    delay(200);
  }

  if(digitalRead(buttonNextPin)==LOW){
    currentSong = (currentSong+1)%totalSongs;
    displayDigit(currentSong+1);
    delay(300);
  }

  if(digitalRead(buttonPrevPin)==LOW){
    currentSong--;
    if(currentSong<0) currentSong=totalSongs-1;
    displayDigit(currentSong+1);
    delay(300);
  }

  // Playback system
  if(playingMelody){
    unsigned long now = millis();
    Song &s = songs[currentSong];

    if(now - previousMillis >= s.durationParts[currentPart][currentNote]){

      playFreq(ch1, 0); // stop primary buzzer between notes

      currentNote++;
      if(currentNote < s.totalNotes[currentPart]){
        playFreq(ch1, s.melodyParts[currentPart][currentNote]);
        previousMillis = now;
      } 
      else {
        currentPart++;
        if(currentPart < s.totalParts){
          currentNote = 0;
          playFreq(ch1, s.melodyParts[currentPart][currentNote]);
          previousMillis = now;
        } else {
          stopSong();
        }
      }
    }
  }
}

void startSong(){
  Song &s = songs[currentSong];

  if(s.totalParts == 0 || s.totalNotes[0] == 0){
    Serial.println("Empty song.");
    return;
  }

  currentPart = 0;
  currentNote = 0;
  playingMelody = true;

  playFreq(ch1, s.melodyParts[currentPart][currentNote]);
  previousMillis = millis();

  Serial.println("Playing...");
}

void stopSong(){
  playingMelody = false;
  stopAll();
  Serial.println("Stopped.");
}
