// ====== CONFIG ======
#define USB_BAUD 9600   // Match this with Serial Monitor baud
// ====================

// Pin mapping (M-Duino analog outputs → Arduino pins)
const int A0_0 = 4;  // A0.0
const int A0_1 = 5;  // A0.1
const int A0_2 = 6;  // A0.2
const int A1_0 = 8;  // A1.0
const int A1_1 = 10; // A1.1
const int A1_2 = 11; // A1.2

void setup() {
  Serial.begin(USB_BAUD);
  delay(250);               // give USB time to enumerate
  pinMode(A0_0, OUTPUT);
  delay(250);               // give USB time to enumerate
  pinMode(A0_1, OUTPUT);
  delay(250);               // give USB time to enumerate
  pinMode(A0_2, OUTPUT);
  delay(250);               // give USB time to enumerate
  pinMode(A1_0, OUTPUT);
  delay(250);               // give USB time to enumerate
  pinMode(A1_1, OUTPUT);
  delay(250);               // give USB time to enumerate
  pinMode(A1_2, OUTPUT);
  Serial.println(F("M-Duino 0–10V Pump Controller Test on pins 4, 5, 6, 8, 10, 11"));
}

void loop() {
  analogWrite(A0_0, 127);
  delay(250);               // give USB time to enumerate
  analogWrite(A0_1, 127);
  delay(250);               // give USB time to enumerate
  analogWrite(A0_2, 127);
  delay(250);               // give USB time to enumerate
  analogWrite(A1_0, 127);
  delay(250);               // give USB time to enumerate
  analogWrite(A1_1, 127);
  delay(250);               // give USB time to enumerate
  analogWrite(A1_2, 127);
  Serial.println(F("M-Duino Pins 4, 5, 6, 8, 10, 11 at 5V"));
  
  analogWrite(A0_0, 254);
  delay(250);               // give USB time to enumerate
  analogWrite(A0_1, 254);
  delay(250);               // give USB time to enumerate
  analogWrite(A0_2, 254);
  delay(250);               // give USB time to enumerate
  analogWrite(A1_0, 254);
  delay(250);               // give USB time to enumerate
  analogWrite(A1_1, 254);
  delay(250);               // give USB time to enumerate
  analogWrite(A1_2, 254);
  Serial.println(F("M-Duino Pins 4, 5, 6, 8, 10, 11 at 5V"));
  delay(1000);
}

