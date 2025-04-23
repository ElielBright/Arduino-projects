#define led_pin 8
#define buzzer_pin 9  // Define the buzzer pin

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);  // Set buzzer pin as OUTPUT
}

void loop() {
  digitalWrite(led_pin, HIGH);  // Turn the LED on
  digitalWrite(buzzer_pin, HIGH); // Turn the buzzer on
  delay(500);  

  digitalWrite(led_pin, LOW);   // Turn the LED off
  digitalWrite(buzzer_pin, LOW); // Turn the buzzer off
  delay(1250);  
}
