#include <Wire.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
const byte address[6] = "00001";

int16_t ax, ay, az;

void setup() {
  Serial.begin(9600);

  Wire.begin();

  // Wake up MPU6050
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();

  Serial.println("TX Ready");
}

void loop() {

  // Read accelerometer values
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();

  char msg[4] = "";

  // Emergency Stop Threshold
  if (ax > 13000 || ax < -13000 ||
      ay > 13000 || ay < -13000)
  {
    strcpy(msg, "STP");
  }

  // Normal Gesture Threshold
  else if (ax > 6000)
  {
    strcpy(msg, "+X");
  }
  else if (ax < -6000)
  {
    strcpy(msg, "-X");
  }
  else if (ay > 6000)
  {
    strcpy(msg, "+Y");
  }
  else if (ay < -6000)
  {
    strcpy(msg, "-Y");
  }

  // Neutral Position
  else
  {
    strcpy(msg, "---");
  }

  radio.write(msg, sizeof(msg));

  Serial.print("AX: ");
  Serial.print(ax);
  Serial.print(" AY: ");
  Serial.print(ay);
  Serial.print(" -> Command: ");
  Serial.println(msg);

  delay(200);
}
