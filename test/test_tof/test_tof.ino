#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
int failed = 0;
void setup() {
  Serial.begin(57600);
  Wire.begin();

  Serial.println("Starting VL53L0X...");

  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
  }

  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop() {

  uint16_t distance = sensor.readRangeContinuousMillimeters();

  if (sensor.timeoutOccurred()) {
    Serial.println("Timeout!");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }

  delay(100);
}