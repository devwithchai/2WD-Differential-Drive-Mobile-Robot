#include <Servo.h>

// --------------------------------------------------
// Servo Configuration
// --------------------------------------------------

const int SERVO_PIN = 10;

const int LEFT_ANGLE   = 0;
const int CENTER_ANGLE = 90;
const int RIGHT_ANGLE  = 180;

Servo scanner;

// --------------------------------------------------
// Initialization
// --------------------------------------------------

void initializeServo()
{
  scanner.attach(SERVO_PIN);

  lookCenter();

  Serial.println("Servo Initialized");
}

// --------------------------------------------------
// Basic Movement Functions
// --------------------------------------------------

void moveTo(int angle)
{
  angle = constrain(angle, 0, 180);

  scanner.write(angle);
}

void lookLeft()
{
  moveTo(LEFT_ANGLE);
}

void lookCenter()
{
  moveTo(CENTER_ANGLE);
}

void lookRight()
{
  moveTo(RIGHT_ANGLE);
}

// --------------------------------------------------
// Smooth Motion
// --------------------------------------------------

void sweepLeftToRight(int delayTime = 15)
{
  for(int angle = LEFT_ANGLE; angle <= RIGHT_ANGLE; angle++)
  {
    scanner.write(angle);
    delay(delayTime);
  }
}

void sweepRightToLeft(int delayTime = 15)
{
  for(int angle = RIGHT_ANGLE; angle >= LEFT_ANGLE; angle--)
  {
    scanner.write(angle);
    delay(delayTime);
  }
}

void scanEnvironment()
{
  sweepLeftToRight();
  sweepRightToLeft();
}

// --------------------------------------------------
// Arduino Setup
// --------------------------------------------------

void setup()
{
  Serial.begin(9600);

  initializeServo();
}

// --------------------------------------------------
// Demo
// --------------------------------------------------

void loop()
{
  Serial.println("Look Left");
  lookLeft();
  delay(1000);

  Serial.println("Look Center");
  lookCenter();
  delay(1000);

  Serial.println("Look Right");
  lookRight();
  delay(1000);

  Serial.println("Scanning...");
  scanEnvironment();

  delay(1000);
}
