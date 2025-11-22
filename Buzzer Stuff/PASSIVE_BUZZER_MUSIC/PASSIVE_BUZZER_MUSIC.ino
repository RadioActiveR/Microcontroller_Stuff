const int buttonOnPin = 2;
const int buttonOffPin = 3;
const int ledPin1 = 13;
const int ledPin2 = 12;
const int buzzerPin = 8;

bool blinking = false;
bool playingMelody = false;

unsigned long previousBlinkMillis = 0;
unsigned long previousToneMillis = 0;
const long blinkInterval = 500;
bool ledState = false;

int melody[] = { 880, 932, 1396, 932, 1396, 0, 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0, 1396, 932, 1396, 0, 1396, 1244, 1108, 1046, 1244, 1108, 1046, 932, 0, 932, 1864, 1661, 1396, 1480, 1661, 1244, 1174, 0 };
int noteDurations[] = { 250, 400, 950, 450, 1050, 450, 400, 400, 400, 400, 400, 400, 400, 400, 200, 800, 450, 1050, 450, 400, 400, 400, 400, 400, 400, 400, 400, 250, 600, 600, 900, 400, 400, 600, 600, 900, 450 };
int totalNotes = sizeof(melody) / sizeof(melody[0]);
int currentNote = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // Start system
  if (digitalRead(buttonOnPin) == LOW) {
    blinking = true;
    playingMelody = true;
    currentNote = 0;
    previousToneMillis = millis();
    tone(buzzerPin, melody[currentNote]);
  }

  // Stop system
  if (digitalRead(buttonOffPin) == LOW) {
    blinking = false;
    playingMelody = false;
    noTone(buzzerPin);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  // LED blinking logic (non-blocking)
  if (blinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousBlinkMillis >= blinkInterval) {
      previousBlinkMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledPin1, ledState);
      digitalWrite(ledPin2, !ledState);
    }
  }

  // Melody playback logic (non-blocking)
  if (playingMelody) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousToneMillis >= noteDurations[currentNote]) {
      noTone(buzzerPin);
      currentNote++;
      if (currentNote < totalNotes) {
        tone(buzzerPin, melody[currentNote]);
        previousToneMillis = currentMillis;
      } else {
        playingMelody = false; // Melody done
      }
    }
  }
}
