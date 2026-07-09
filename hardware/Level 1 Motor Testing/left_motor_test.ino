const int IN1 = 2;
const int IN2 = 3;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {

  // Test 1
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(3000);

  // Stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(2000);

  // Test 2
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(3000);

  // Stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  while (1);
}