// Simple LED blink

const int led = LED_BUILTIN;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(5000);
  digitalWrite(led, LOW);
  delay(1000);
  Serial.println("helloworld");
}

