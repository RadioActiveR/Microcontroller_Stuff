#include <Servo.h>

// Servo objects
Servo panServo;
Servo tiltServo;

// Joystick pins
const int joyX = A0;
const int joyY = A1;

// Servo pins
const int panPin = 9;
const int tiltPin = 10;

void setup() {
  panServo.attach(panPin);
  tiltServo.attach(tiltPin);

  // Start at middle position
  panServo.write(90);
  tiltServo.write(90);

  Serial.begin(9600);
}

void loop() {
  int xVal = analogRead(joyX); // 0-1023
  int yVal = analogRead(joyY); // 0-1023

  // Map joystick to servo angle (0-180)
  int panAngle = map(xVal, 0, 1023, 0, 180);
  int tiltAngle = map(yVal, 0, 1023, 0, 180);

  //------------------------------------------
  // OPTIONAL AXIS REVERSAL
  // Uncomment these if you want to flip direction:

  // panAngle = 180 - panAngle;   // reverse left/right
  // tiltAngle = 180 - tiltAngle; // reverse up/down
  //------------------------------------------

  // Write to servos
  panServo.write(panAngle);
  tiltServo.write(tiltAngle);

  // Debug (optional)
  Serial.print("Pan: ");
  Serial.print(panAngle);
  Serial.print(" | Tilt: ");
  Serial.println(tiltAngle);

  delay(10); // fast response
}
