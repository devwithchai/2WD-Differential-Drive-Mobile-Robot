// ---------------- Motor Pins ----------------

const int ENA = 9;
const int ENB = 6;

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

void initializeMotors()
{
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();
}

void forward(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup()
{
  Serial.begin(9600);

  initializeMotors();

  Serial.println("Motor Controller Initialized");
}

void loop()
{
  forward(255);
  delay(3000);

  stopRobot();
  delay(1000);

  forward(150);
  delay(3000);

  stopRobot();
  delay(1000);

  backward(200);
  delay(3000);

  stopRobot();
  delay(1000);

  left(180);
  delay(3000);

  stopRobot();
  delay(1000);

  right(180);
  delay(3000);

  stopRobot();
  delay(2000);

  while (1);
}
