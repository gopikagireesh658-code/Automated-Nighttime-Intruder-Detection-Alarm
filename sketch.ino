const int pirPin = 5;
const int buzzer = 6;
const int ldrPin = A1;

const int led1 = 12;
const int led2 = 11;
const int led3 = 10;
const int led4 = 9;
const int led5 = 8;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  int lightLevel = analogRead(ldrPin);

  Serial.print("LDR: ");
  Serial.print(lightLevel);
  Serial.print(" Motion: ");
  Serial.println(motion);

  // Night condition (adjust threshold if needed)
  if (lightLevel < 500 && motion == HIGH) {

    // Turn ON all lights
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);

    // Ambulance siren
    for (int i = 0; i < 5; i++) {
      tone(buzzer, 800);
      delay(400);

      tone(buzzer, 1200);
      delay(400);
    }

    noTone(buzzer);
  }
  else {
    // Turn OFF everything
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

    noTone(buzzer);
  }

  delay(100);
}