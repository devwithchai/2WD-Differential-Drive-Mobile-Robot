HardwareSerial MySerial(2);

void setup()
{
  Serial.begin(115200);

  MySerial.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("ESP32 Ready");
  delay(2000);   // Wait for Arduino to boot
}

void loop()
{
  MySerial.write("F");
  Serial.println("Sent -> F");
  delay(3000);

  MySerial.write("L");
  Serial.println("Sent -> L");
  delay(3000);

  MySerial.write("R");
  Serial.println("Sent -> R");
  delay(3000);

  MySerial.write("B");
  Serial.println("Sent -> B");
  delay(3000);

  MySerial.write("S");
  Serial.println("Sent -> S");
  delay(3000);
}