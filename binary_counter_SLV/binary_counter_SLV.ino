
// Tukaj se vnesejo indeksi pinov na katere so priključene LED diode
const int pini[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
bool stevke[sizeof(pini)];

void setup() {
  for (int i = 0; i < sizeof(pini)/sizeof(int); i++) {
    pinMode(pini[i], OUTPUT);
  }
}

void loop() {
  // Posodobi LED diode
  for (int i = 0; i < sizeof(pini)/sizeof(int); i++) {
    digitalWrite(pini[i], stevke[i]);
  }

  // Prištej
  bool prenesi = true;
  for (int i = 0; i < sizeof(pini)/sizeof(int); i++) {
    if (stevke[i] && prenesi) {
      stevke[i] = false;
    }
    else if (prenesi) {
      stevke[i] = true;
      prenesi = false;
    }
  }

  // Počakaj
  delay(20);
}
