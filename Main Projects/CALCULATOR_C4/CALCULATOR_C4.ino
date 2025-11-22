#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String equation = "";
bool showResult = false;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == 'C') {
      equation = "";
      showResult = false;
      lcd.clear();
    } else if (key == '=') {
      if (equation == "7355608") {
        showResult = true;
        lcd.clear();
        delay(3000);
        lcd.setCursor(0, 0);
        lcd.print("   * *    * *");
        lcd.setCursor(0, 1);
        lcd.print("  * * BOOM * *");
      } else {
        float result = evaluate(equation);
        showResult = true;
        lcd.setCursor(0, 1);
        lcd.print("= ");
        lcd.print(result);
      }
    } else {
      if (showResult) {
        equation = "";
        showResult = false;
        lcd.clear();
      }

      if (equation.length() < 16) {
        equation += key;
        lcd.setCursor(0, 0);
        lcd.print(equation);
      }
    }
  }
}

float evaluate(String expr) {
  char ops[] = {'+', '-', '*', '/'};
  for (int i = 0; i < sizeof(ops); i++) {
    int index = expr.indexOf(ops[i]);
    if (index > 0) {
      float num1 = expr.substring(0, index).toFloat();
      float num2 = expr.substring(index + 1).toFloat();
      switch (ops[i]) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? num1 / num2 : 0;
      }
    }
  }
  return 0;
}
