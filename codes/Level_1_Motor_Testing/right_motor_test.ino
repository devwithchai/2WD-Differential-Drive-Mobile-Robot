const int IN3 = 4;
const int IN4 = 5;

void setup() {
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  // Test 1
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3000);

  // Stop
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2000);

  // Test 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3000);

  // Stop
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  while (1);
}