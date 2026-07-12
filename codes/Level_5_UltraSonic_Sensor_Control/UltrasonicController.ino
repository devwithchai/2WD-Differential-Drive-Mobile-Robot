/*
---------------------------------------------------------
2WD Differential Drive Mobile Robot

Level 5 - Ultrasonic Controller

---------------------------------------------------------
*/

// --------------------------------------------------
// Pin Configuration
// --------------------------------------------------

const int TRIG_PIN = 11;
const int ECHO_PIN = 12;

// --------------------------------------------------
// Initialization
// --------------------------------------------------

void initializeUltrasonic()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("Ultrasonic Sensor Initialized");
}

// --------------------------------------------------
// Raw Distance Measurement
// --------------------------------------------------

float getDistance()
{
  // Ensure TRIG is LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Generate 10 µs trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // No echo received
  if (duration == 0)
  {
    return -1;
  }

  // Convert to distance (cm)
  return duration * 0.0343 / 2.0;
}

// --------------------------------------------------
// Filtered Distance
// --------------------------------------------------

float getFilteredDistance()
{
  float sum = 0;
  int validReadings = 0;

  for (int i = 0; i < 5; i++)
  {
    float distance = getDistance();

    if (distance > 0)
    {
      sum += distance;
      validReadings++;
    }

    delay(20);
  }

  if (validReadings == 0)
  {
    return -1;
  }

  return sum / validReadings;
}

// --------------------------------------------------
// Obstacle Detection
// --------------------------------------------------

bool isObstacleDetected(float distance, float threshold)
{
  if (distance < 0)
  {
    return false;
  }

  return (distance <= threshold);
}

// --------------------------------------------------
// Range Check
// --------------------------------------------------

bool isWithinRange(float distance,
                   float minDistance,
                   float maxDistance)
{
  if (distance < 0)
  {
    return false;
  }

  return (distance >= minDistance &&
          distance <= maxDistance);
}

// --------------------------------------------------
// Arduino Setup
// --------------------------------------------------

void setup()
{
  Serial.begin(9600);

  initializeUltrasonic();
}

// --------------------------------------------------
// Main Program
// --------------------------------------------------

void loop()
{
  // Read sensor ONLY ONCE
  float distance = getFilteredDistance();

  // Invalid reading
  if (distance < 0)
  {
    Serial.println("No Valid Echo");
    Serial.println("----------------------");
    delay(500);
    return;
  }

  // Display measured distance
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  // Obstacle Detection
  if (isObstacleDetected(distance, 20))
  {
    Serial.println("Obstacle Detected");
  }
  else
  {
    Serial.println("Path Clear");
  }

  // Example Range Check (optional)
  /*
  if (isWithinRange(distance, 10, 30))
  {
    Serial.println("Object is between 10 and 30 cm");
  }
  */

  Serial.println("----------------------");

  delay(500);
}
