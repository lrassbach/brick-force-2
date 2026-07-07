#include <TinyGPSPlus.h>

TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);      // USB serial
  Serial1.begin(9600);       // GPS serial
}

void loop() {
  while (Serial1.available()) {
    gps.encode(Serial1.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("Lat: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Lng: ");
    Serial.println(gps.location.lng(), 6);
  }
  else {
    Serial.println("No reading");
  }
}
