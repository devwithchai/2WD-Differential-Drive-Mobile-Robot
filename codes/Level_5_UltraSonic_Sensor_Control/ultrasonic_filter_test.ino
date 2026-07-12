// --------------------------------------------------
// HC-SR04 Filtered Distance Measurement
// Level 5 - Experiment 2
// --------------------------------------------------

const int TRIG_PIN = 11;
const int ECHO_PIN = 12;

float getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30 ms timeout

  if (duration == 0)
  {
    return -1; // No echo received
  }

  return duration * 0.0343 / 2.0;
}

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("HC-SR04 Filter Test");
}

void loop()
{
  float sum = 0;
  int validReadings = 0;

  for (int i = 0; i < 5; i++)
  {
    float d = getDistance();

    if (d > 0)
    {
      sum += d;
      validReadings++;
    }

    delay(20);
  }

  if (validReadings > 0)
  {
    float average = sum / validReadings;

    Serial.print("Filtered Distance: ");
    Serial.print(average);
    Serial.println(" cm");
  }
  else
  {
    Serial.println("No Valid Echo");
  }

  delay(300);
}