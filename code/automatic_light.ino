int pirPin = 2;
int ldrPin = A0;
int relayPin = 8;

int ldrThreshold = 500;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int pirState = digitalRead(pirPin);
  int ldrValue = analogRead(ldrPin);

  Serial.print("PIR: ");
  Serial.print(pirState);
  Serial.print(" | LDR: ");
  Serial.println(ldrValue);

  if (pirState == HIGH && ldrValue < ldrThreshold) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }

  delay(500);
}

