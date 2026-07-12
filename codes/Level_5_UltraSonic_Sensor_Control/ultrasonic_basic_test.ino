// --------------------------------------------------
// HC-SR04 Basic Distance Measurement
// Level 5 - Experiment 1
// --------------------------------------------------

const int TRIG_PIN = 11;
const int ECHO_PIN = 12;

long duration;
float distance;

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("--------------------------------");
  Serial.println("HC-SR04 Basic Distance Test");
  Serial.println("--------------------------------");
}

void loop()
{
  // Ensure TRIG starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Generate a 10 µs trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance
  distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}