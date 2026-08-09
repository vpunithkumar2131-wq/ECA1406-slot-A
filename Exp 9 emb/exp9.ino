int trig = 10;
int echo = 9;
long duration;
int cm;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. Ensure the trigger pin is low first
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // 2. Send a clean 10 microsecond HIGH pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 3. Read the echo travel time in microseconds
  duration = pulseIn(echo, HIGH);

  // 4. Calculate distance: Speed of sound is ~0.034 cm/us
  // We divide by 2 because the sound travels to the object and back.
  cm = duration * 0.034 / 2;

  // 5. Print to Serial Monitor
  Serial.print("Distance = ");
  Serial.print(cm);
  Serial.println(" cm");

  delay(200); // Small delay to make the serial monitor readable
}
