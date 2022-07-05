// Documentation for how to connect the HX711 to the wheatstone bridge:
// https://learn.sparkfun.com/tutorials/load-cell-amplifier-hx711-breakout-hookup-guide#hardware-hookup-

#include <HX711.h>

const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;
const float GAUGE_FACTOR = 2.1;   // gauge factor is a property of the strain gauge

HX711 strainGauge;

//const long LOADCELL_OFFSET = 50682624;
//const long LOADCELL_DIVIDER = 5895655;

void setup() {
  Serial.begin(115200);
  strainGauge.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);   // this function also automatically selects channel A and sets gain to 
  strainGauge.set_gain(64);                    // sets the gain of channel A to 64 which corresponds to an input of ±40mV
  //strainGauge.set_scale(LOADCELL_DIVIDER);
  //strainGauge.set_offset(LOADCELL_OFFSET);
  //for(int i = 0; i < 100; i++)                 // flushes the first few readings
    //float x = strainGauge.read();
}

void loop() {
  float voltage = strainGauge.read();
  voltage = ((voltage / 8388607) * 5) / 64;   // 2^23 - 1 = 8388607. Dividing to reverse the amplifier gain.
  //float strain = (4 * voltage)/(5.0 * GAUGE_FACTOR);
  //Serial.print(voltage,5);
  //Serial.print("\t");
  Serial.println(voltage,6);
}
