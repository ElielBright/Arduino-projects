#include <LiquidCrystal.h>

// Pin assignment based on your connections
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // RS, E, D4, D5, D6, D7

void setup() {
  lcd.begin(16, 2); // Initialize the LCD (16 columns, 2 rows)
  delay(1000); // Wait for the LCD to initialize
  lcd.setCursor(0, 0); // Set the cursor to the top-left corner
  lcd.print("Waiting..."); // Display a test message
}


void loop() {
  // No need to do anything in loop for this simple test
}
