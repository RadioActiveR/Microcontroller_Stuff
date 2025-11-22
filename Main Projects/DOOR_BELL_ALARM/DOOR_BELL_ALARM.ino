const int buttonOnPin = 2;
const int buttonOffPin = 3;
const int ledPin1 = 13;
const int ledPin2 = 12;
const int buzzerPin = 8;

bool blinking = false;
bool buzzerOn = false;

unsigned long previousBlinkMillis = 0;
unsigned long buzzerStartMillis = 0;

const long blinkInterval = 500;
const long buzzerDuration = 2000;
bool ledState = false;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
}

void loop() {
  // Turn ON system
  if (digitalRead(buttonOnPin) == LOW) {
    blinking = true;
    buzzerOn = true;
    buzzerStartMillis = millis();
    digitalWrite(buzzerPin, HIGH);
  }

  // Turn OFF system
  if (digitalRead(buttonOffPin) == LOW) {
    blinking = false;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Handle buzzer timing
  if (buzzerOn && millis() - buzzerStartMillis >= buzzerDuration) {
    buzzerOn = false;
    digitalWrite(buzzerPin, LOW);
  }

  // Handle blinking LEDs
  if (blinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousBlinkMillis >= blinkInterval) {
      previousBlinkMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledPin1, ledState);
      digitalWrite(ledPin2, !ledState);
    }
  }
}
