const int ldrPin = A0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(A0);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Set threshold based on actual readings
  if (ldrValue < 400) {
    digitalWrite(ledPin, HIGH); // It's dark, turn LED on
      delay(1000);

  } else {
    digitalWrite(ledPin, LOW);  // It's bright, turn LED off
      delay(1000);

  }

  delay(200);
}
