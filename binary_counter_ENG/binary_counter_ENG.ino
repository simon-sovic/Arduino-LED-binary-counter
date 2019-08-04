
// Put the pin indexes in this array
const int pins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
bool digits[sizeof(pins)];

void setup() {
  for (int i = 0; i < sizeof(pins)/sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // Update the LEDs
  for (int i = 0; i < sizeof(pins)/sizeof(int); i++) {
    digitalWrite(pins[i], digits[i]);
  }

  // Add 1
  bool carry = true;
  for (int i = 0; i < sizeof(pins)/sizeof(int); i++) {
    if (digits[i] && carry) {
      digits[i] = false;
    }
    else if (carry) {
      digits[i] = true;
      carry = false;
    }
  }

  // Wait
  delay(20);
}
