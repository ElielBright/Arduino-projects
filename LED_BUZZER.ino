#include <Servo.h>

#define X_PIN A0   // X-axis joystick pin
#define Y_PIN A1   // Y-axis joystick pin
#define SW_PIN 2   // Joystick button pin

Servo s1;
bool controlX = true;  // Start by controlling X-axis

void setup() {
  Serial.begin(9600);
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(SW_PIN, INPUT_PULLUP);  // Enable internal pull-up resistor

  s1.attach(3);  // Servo connected to pin 3
  s1.write(90);  // Start at middle position
}

void loop() {
  int x_data = analogRead(X_PIN);  // Read X-axis
  int y_data = analogRead(Y_PIN);  // Read Y-axis
  int sw_data = digitalRead(SW_PIN);  // Read button state

  // If the button is pressed, switch control between X and Y
  if (sw_data == LOW) {
    controlX = !controlX;  // Toggle between X and Y control
    delay(300);  // Small delay to prevent rapid switching
  }

  // Choose which axis to use
  int servo_pos;
  if (controlX) {
    servo_pos = map(x_data, 0, 1023, 0, 180);  // Use X-axis
  } else {
    servo_pos = map(y_data, 0, 1023, 0, 180);  // Use Y-axis
  }

  servo_pos = constrain(servo_pos, 0, 180);  // Keep within limits
  s1.write(servo_pos);  // Move servo to mapped position

  // Print values for debugging
  Serial.print("Control: ");
  Serial.print(controlX ? "X-axis" : "Y-axis");
  Serial.print("\tServo Position: ");
  Serial.println(servo_pos);

  delay(20);  // Small delay for smooth movement
}
