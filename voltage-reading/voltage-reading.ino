// Created: 6/22/2022
// Author: Sumit Das (sumit.das.f@gmail.com

#define V0_positive A1            // this is the positive terminal of the output voltage (arbitrary)
#define V0_negative A0            // negative terminal
const float gauge_factor = 2.1;  // gauge factor is a property of the strain gauge

void setup() {
  Serial.begin(9600);
  pinMode(V0_positive, INPUT);
  pinMode(V0_negative, INPUT);
}

void loop() {
  float voltage_positive = voltageOf(analogRead(V0_positive));
  float voltage_negative = voltageOf(analogRead(V0_negative));
  float outputVoltage = voltage_positive - voltage_negative;
  float strain = (4 * outputVoltage)/(5.0 * gauge_factor);
  Serial.print("Voltage: ");
  Serial.print(outputVoltage);
  Serial.print("\tStrain: ");
  Serial.println(strain);
  delay(100);
}

float voltageOf(int value){
  return value/1023.0 * 5.0;
}
