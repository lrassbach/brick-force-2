#include <Wire.h>

void setup() {
  Serial.begin(57600);
  Wire.begin();
  Serial.println("I2C Scanner running...");
}

void loop() {
  Serial.println("Scanning...");
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C device at 0x");
      Serial.println(addr, HEX);
    }
  }
  Serial.println("Done.\n");
  delay(2000);
}