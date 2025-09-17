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
/*
const int PUMP_CX1_SOURCE = 5;   // A0.1
const int PUMP_CX1_LOAD   = 4;   // A0.0
const int PUMP_CX2_SOURCE = 11;  // A1.2
const int PUMP_CX2_LOAD   = 8;   // A1.0
*/
/*
// Current setpoints (percent 0–100)
float spCX1S = 0, spCX1L = 0, spCX2S = 0, spCX2L = 0;

// ----- Helpers
int pctToPwm(float pct) {
  if (pct < 0)   pct = 0;
  if (pct > 100) pct = 100;
  return (int)round((pct / 100.0) * 255.0);
}

void applyAll() {
  analogWrite(PUMP_CX1_SOURCE, pctToPwm(spCX1S));
  analogWrite(PUMP_CX1_LOAD,   pctToPwm(spCX1L));
  analogWrite(PUMP_CX2_SOURCE, pctToPwm(spCX2S));
  analogWrite(PUMP_CX2_LOAD,   pctToPwm(spCX2L));
}

void printStatus() {
  Serial.println(F("---- Pump Status (% setpoint ≈ 0–10V) ----"));
  Serial.print (F("CX1S: ")); Serial.print(spCX1S, 1); Serial.println(F("%  (A0.1 → pin 5)"));
  Serial.print (F("CX1L: ")); Serial.print(spCX1L, 1); Serial.println(F("%  (A0.0 → pin 4)"));
  Serial.print (F("CX2S: ")); Serial.print(spCX2S, 1); Serial.println(F("%  (A1.2 → pin 11)"));
  Serial.print (F("CX2L: ")); Serial.print(spCX2L, 1); Serial.println(F("%  (A1.0 → pin 8)"));
  Serial.println(F("------------------------------------------"));
}

void printHelp() {
  Serial.println(F("Commands:"));
  Serial.println(F("  CX1S <pct>   Set CX1_Source (A0.1 → pin 5) to 0–100%"));
  Serial.println(F("  CX1L <pct>   Set CX1_Load   (A0.0 → pin 4) to 0–100%"));
  Serial.println(F("  CX2S <pct>   Set CX2_Source (A1.2 → pin 11) to 0–100%"));
  Serial.println(F("  CX2L <pct>   Set CX2_Load   (A1.0 → pin 8) to 0–100%"));
  Serial.println(F("  ALL  <pct>   Set ALL pumps to 0–100%"));
  Serial.println(F("  STATUS       Show current setpoints"));
  Serial.println(F("  HELP or ?    Show this help"));
  Serial.println(F("Notes: Serial Monitor = 9600 baud, line ending = Newline."));
}

void handleSet(const String& id, float pct) {
  if (pct < 0 || pct > 100) {
    Serial.println(F("Error: percent must be 0–100."));
    return;
  }
  bool ok = true;
  if      (id.equalsIgnoreCase("CX1S")) spCX1S = pct;
  else if (id.equalsIgnoreCase("CX1L")) spCX1L = pct;
  else if (id.equalsIgnoreCase("CX2S")) spCX2S = pct;
  else if (id.equalsIgnoreCase("CX2L")) spCX2L = pct;
  else if (id.equalsIgnoreCase("ALL"))  { spCX1S = spCX1L = spCX2S = spCX2L = pct; }
  else ok = false;

  if (!ok) { Serial.println(F("Unknown pump ID. Use CX1S, CX1L, CX2S, CX2L, or ALL.")); return; }
  applyAll();
  Serial.print(id); Serial.print(F(" set to ")); Serial.print(pct, 1); Serial.println(F("%"));
}

void parseLine(String line) {
  line.trim();
  if (!line.length()) return;
  int sp = line.indexOf(' ');
  String t0 = (sp > 0) ? line.substring(0, sp) : line;
  String t1 = (sp > 0) ? line.substring(sp + 1) : "";

  if (t0.equalsIgnoreCase("HELP") || t0 == "?")       printHelp();
  else if (t0.equalsIgnoreCase("STATUS"))             printStatus();
  else if (t0.equalsIgnoreCase("CX1S") || t0.equalsIgnoreCase("CX1L") ||
           t0.equalsIgnoreCase("CX2S") || t0.equalsIgnoreCase("CX2L") ||
           t0.equalsIgnoreCase("ALL")) {
    float pct = t1.toFloat();
    handleSet(t0, pct);
  } else {
    Serial.println(F("Unrecognized command. Type HELP or ?"));
  }
}
*/

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
  /*
  pinMode(PUMP_CX1_SOURCE, OUTPUT);
  pinMode(PUMP_CX1_LOAD,   OUTPUT);
  pinMode(PUMP_CX2_SOURCE, OUTPUT);
  pinMode(PUMP_CX2_LOAD,   OUTPUT);
  applyAll();
  Serial.println(F("M-Duino 0–10V Pump Controller"));
  printHelp();
  printStatus();
  */
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
  /*
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    parseLine(line);
    } */
}

