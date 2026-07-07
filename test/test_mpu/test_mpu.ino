// read MPU
#include <Wire.h>

float RateRoll, RatePitch, RateYaw;


const int led = LED_BUILTIN;

void gyro_signals(void) {
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,6, false);
  /*
  Reading is 16 bit signed integer
  I2C only sends one byte per transfer;
  High byte is the upper 8 bits
  Low byte is the lower 8 bits
  ex:
  00011010 00000000
  OR
  00000000 11110000
  ------------------
  00011010 11110000
  */
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
}


void setup() {
  Serial.begin(57600);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05); // low-pass filter
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x08); // set the sensitivity scale factor
  Wire.endTransmission();
}

void loop() {
    gyro_signals();
    Serial.print("Roll rate = ");
    Serial.print(RateRoll);
    // Serial.print("\n");
    Serial.print("; Pitch rate = ");
    Serial.print(RatePitch);
    // Serial.print("\n");
    Serial.print("; Yaw rate = ");
    Serial.print(RateYaw);
    Serial.print("\n");
    delay(1000);
}


