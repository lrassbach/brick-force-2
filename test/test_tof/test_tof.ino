#include <Wire.h>
#include <VL53L0X.h>

const uint8_t ADDR_SENSOR1 = 0x30;
const uint8_t ADDR_SENSOR2 = 0x31;
const uint8_t ADDR_SENSOR3 = 0x32;

VL53L0X sensor1; // left -- BLUE
VL53L0X* sensor1_ptr = &sensor1;
VL53L0X sensor2; // center -- YELLOW
VL53L0X* sensor2_ptr = &sensor2;
VL53L0X sensor3; // right -- GREEN
VL53L0X* sensor3_ptr = &sensor3;

const int xshut1 = 23;
const int xshut2 = 22;
const int xshut3 = 9;

int failed = 0;

int start_sensor(VL53L0X* sensor, const int xshut, const uint8_t addr){
  
  pinMode(xshut, OUTPUT);
  digitalWrite(xshut, LOW);
  delay(10);
  // wake
  digitalWrite(xshut, HIGH);
  delay(10);
  // initialize
  sensor->setTimeout(500);
  if(!sensor->init()){
    return 1;
  }
  sensor->setAddress(addr);
  sensor->startContinuous();

  return 0;
}

void setup() {
  Serial.begin(57600);
  
  delay(2);
  Serial.println("Starting VL53L0X...");
  Wire.begin();

  int rc = 0;

  rc += start_sensor(sensor1_ptr, xshut1, ADDR_SENSOR1);
  rc += start_sensor(sensor2_ptr, xshut1, ADDR_SENSOR2);
  rc += start_sensor(sensor3_ptr, xshut1, ADDR_SENSOR3);
  if(rc != 0){
    Serial.println("Error in sensor initialization");
    exit(1);
  }

  delay(1);
  Serial.println("All sensors started OK");

}

int read_sensor(VL53L0X* sensor){
  uint16_t distance = sensor->readRangeContinuousMillimeters();

  if (sensor->timeoutOccurred()) {
    Serial.println("Timeout!");
    return 1;
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
    return 0;
  }

}

void loop() {
  Serial.println("Left Sensor (1)");
  read_sensor(&sensor1);
  delay(100);
  Serial.println("middle Sensor (2)");
  read_sensor(&sensor2);
  delay(100);
  Serial.println("right Sensor (3)");
  read_sensor(&sensor3);
  delay(100);
}