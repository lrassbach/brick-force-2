// Teensy 4.1 & TB6612FNG Pin Definitions
const int STBY = 11;   // standby pin BLUE

// Motor A
const int PWMA = 5;   // speed control (PWM) GREY
const int AIN1 = 3;   // direction 1  ORANGE
const int AIN2 = 4;   // direction 2 BROWN

// Motor B
const int BIN1 = 2;   // direction 1 GREEN
const int BIN2 = 6;   // direction 2 PURPLE
const int PWMB = 10;   // speed control (PWM) YELLOW

void setup() {
  // Set all motor control pins as outputs
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Set Teensy 4.1 PWM frequency to 20,000 Hz (Ultrasonic / Quiet)
  // This stops the motor from making an annoying high-pitched whine!
  analogWriteFrequency(PWMA, 20000);
  analogWriteFrequency(PWMB, 20000);
}

void loop() {
  // Enable the motor driver (bring out of standby)
  digitalWrite(STBY, HIGH);

  // 1. Move both motors FORWARD at roughly half speed (127/255)
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 127);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 127);
  delay(2000); // Run for 2 seconds

  // 2. STOP both motors for 1 second
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  delay(1000);

  // 3. Move both motors REVERSE at full speed (255/255)
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 255);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 255);
  delay(2000); // Run for 2 seconds

  // 4. BRAKE both motors for 2 seconds before looping
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
  delay(2000);
}
