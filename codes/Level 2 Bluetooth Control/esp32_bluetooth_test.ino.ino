#include "BluetoothSerial.h"

HardwareSerial MySerial(2);      // UART2
BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(115200);

  MySerial.begin(9600, SERIAL_8N1, 16, 17);

  if (!SerialBT.begin("Chaitanya_Robot"))
  {
    Serial.println("Bluetooth Failed!");
    while (1);
  }

  Serial.println("Bluetooth Started");
}

void loop()
{
  if (SerialBT.available())
  {
    char command = SerialBT.read();

    // Ignore newline characters
    if (command == '\n' || command == '\r')
      return;

    Serial.print("Bluetooth Received: ");
    Serial.println(command);

    // Send to Arduino
    MySerial.write(command);

    Serial.print("Sent to Arduino: ");
    Serial.println(command);

    // Send confirmation back to phone
    SerialBT.print("Command Sent: ");
    SerialBT.println(command);
  }
}