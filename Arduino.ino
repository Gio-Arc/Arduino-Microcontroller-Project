const int ledPins[] = {10, 11, 12, 13};
const int buttonOnPin = 2;
const int buttonOffPin = 3;
const int potPin = A0;

bool lastButtonOnState = HIGH;
bool lastButtonOffState = HIGH;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);

  Serial.begin(9600); // Aktifkan Serial Monitor
  Serial.println("Program dimulai...");
}

void loop() {
  int potValue = analogRead(potPin);
  int delayTime = map(potValue, 0, 1023, 100, 1000); // kecepatan bergantian

  bool buttonOnState = digitalRead(buttonOnPin);
  bool buttonOffState = digitalRead(buttonOffPin);

  Serial.print("Potensiometer: ");
  Serial.print(potValue);
  Serial.print(" | Delay: ");
  Serial.print(delayTime);
  Serial.print(" ms");

  // Tombol ON ditekan
  if (buttonOnState == LOW && lastButtonOnState == HIGH) {
    Serial.println(" | Tombol ON ditekan");
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
      Serial.print("LED ");
      Serial.print(i + 1);
      Serial.println(" NYALA");
      delay(delayTime);
    }
  }

  // Tombol OFF ditekan
  else if (buttonOffState == LOW && lastButtonOffState == HIGH) {
    Serial.println(" | Tombol OFF ditekan");
    for (int i = 3; i >= 0; i--) {
      digitalWrite(ledPins[i], LOW);
      Serial.print("LED ");
      Serial.print(i + 1);
      Serial.println(" MATI");
      delay(delayTime);
    }
  } else {
    Serial.println(" | Tidak ada tombol ditekan");
  }

  lastButtonOnState = buttonOnState;
  lastButtonOffState = buttonOffState;
}