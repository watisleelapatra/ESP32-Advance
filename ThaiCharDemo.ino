#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create the LCD object with I2C address 0x27 (adjust as necessary)
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Define custom characters for some Thai alphabets
byte thaiChars[8][8] = {
  { 0b00110, 0b01001, 0b11001, 0b01001, 0b01001, 0b01001, 0b01001, 0b00000 }, // ก
  { 0b10000, 0b01001, 0b11001, 0b01001, 0b01001, 0b01001, 0b00110, 0b00000 }, // ข
  { 0b01110, 0b10001, 0b10001, 0b10001, 0b11101, 0b10101, 0b10001, 0b00000 }, // ค
  { 0b00011, 0b00011, 0b00001, 0b00001, 0b01001, 0b00101, 0b00011, 0b00000 }, // ง
  { 0b00110, 0b01001, 0b00001, 0b00001, 0b00101, 0b00011, 0b00001, 0b00000 }, // จ
  { 0b01100, 0b10010, 0b10010, 0b00010, 0b11010, 0b01101, 0b01010, 0b00000 }, // ฉ
  { 0b00001, 0b10001, 0b01010, 0b10010, 0b01010, 0b01010, 0b00100, 0b00000 }, // ช
  { 0b00001, 0b11001, 0b01010, 0b10010, 0b01010, 0b01010, 0b00100, 0b00000 }  // ซ
};

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Create custom characters
  for (int i = 0; i < 8; i++) {
    lcd.createChar(i, thaiChars[i]);
  }

  // Clear the screen
  lcd.clear();

  // Display the Thai characters
  displayThaiCharacters();
}

void loop() {
  // Do nothing in loop
}

void displayThaiCharacters() {
  lcd.setCursor(0, 0); // First row
  for (int i = 0; i < 8; i++) {
    lcd.write(byte(i)); // Display custom characters
  }
}
