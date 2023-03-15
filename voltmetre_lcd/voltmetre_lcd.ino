#include <LiquidCrystal.h>

#define R1 2000
#define R2 560
#define PIN_VOLTMETRE A0

#define MAX_VOLTS_INPUT 22.857F
#define RATION_VOLT (float)(22.857F / 5.0F)
#define RATIO_ADC (float)(5.0F / 1024.0F)

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
/**
* caluculate final value of vin before kirshoff bridge
* @param vADC value on ADC pin
*/
float calculateVin(uint16_t vADC) {
  return RATIO_ADC * (float)vADC * RATION_VOLT;
}
void lcdStartupScreen() {
  lcd.setCursor(5, 0);
  lcd.print("Orsys");
  lcd.setCursor(3, 0);
  lcd.print("Voltmetre");
}
void printVoltageValue(float value) {
  lcd.setCursor(0, 1);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print(value);
  lcd.print("V");
}
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcdStartupScreen();
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("tension en A0");
}

void loop() {
  printVoltageValue(calculateVin(analogRead(PIN_VOLTMETRE)));
  delay(900);
}
