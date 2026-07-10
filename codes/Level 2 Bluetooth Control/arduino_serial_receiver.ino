#include <SoftwareSerial.h>

SoftwareSerial ESPSerial(10, 11);   // RX, TX

// Motor Driver Pins
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

// -------------------- Setup --------------------

void setup()
{
  Serial.begin(9600);
  ESPSerial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();

  Serial.println("Arduino Ready");
}

// -------------------- Motor Functions --------------------

void forward()
{
  Serial.println("Inside Forward()");
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// -------------------- Main Loop --------------------

void loop()
{
  if (ESPSerial.available())
  {
    char command = ESPSerial.read();

    Serial.print("Received: ");
    Serial.println(command);

    switch (command)
    {
      case 'F':
        Serial.println("Forward");
        forward();
        break;

      case 'B':
        Serial.println("Backward");
        backward();
        break;

      case 'L':
        Serial.println("Left");
        left();
        break;

      case 'R':
        Serial.println("Right");
        right();
        break;

      case 'S':
        Serial.println("Stop");
        stopRobot();
        break;

      default:
        Serial.println("Unknown Command");
        stopRobot();
        break;
    }
  }
}