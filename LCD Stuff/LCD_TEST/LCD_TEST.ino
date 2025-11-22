#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HELLO");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WORLD");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TESTING");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CALCULATOR");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SCREEN");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SUCCESS!");
  delay(2000);
}
