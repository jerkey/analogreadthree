#define VOLTAGE_PIN A0
#define CHARGE_PIN A1
#define DISCHARGE_PIN A2

#define PRINT_TIME 1000

uint32_t lastPrintTime = 0;

void setup() {
  Serial.begin(57600);
  lastPrintTime = millis();
}

uint32_t voltage, charge, discharge;
uint32_t voltageAdder, chargeAdder, dischargeAdder;
uint16_t analogAdds = 0;

void updateAnalogs() { // divide analog oversamplers to get precise values
  voltage = voltageAdder / analogAdds;
  charge = chargeAdder / analogAdds;
  discharge = dischargeAdder / analogAdds;
  chargeAdder = 0;
  voltageAdder = 0;
  dischargeAdder = 0;
  analogAdds = 0;
}

void readAnalogs() {
  voltageAdder += analogRead(VOLTAGE_PIN);
  chargeAdder += analogRead(CHARGE_PIN);
  dischargeAdder += analogRead(DISCHARGE_PIN);
  analogAdds++;
}

void loop() {
  readAnalogs();
  if (millis() - lastPrintTime > PRINT_TIME) {
    updateAnalogs();
    Serial.println(String(voltage)+','+String(charge)+','+String(discharge));
    lastPrintTime = millis();
  }
}
