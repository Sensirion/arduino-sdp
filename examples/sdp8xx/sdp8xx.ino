#include <Wire.h>

#include <sdpsensor.h>

SDP8XXSensor sdp;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  delay(1000); // let serial console settle
  do {
    int ret = sdp.init();
    if (ret == 0) {
      Serial.print("init(): success\n");
      break;
    } else {
      Serial.print("init(): failed, ret = ");
      Serial.println(ret);
      delay(1000);
    }
  } while(true);
}

void loop() {
  int ret = sdp.readSample();
  if (ret == 0) {
    Serial.print("Differential pressure: ");
    Serial.print(sdp.getDifferentialPressure());
    Serial.print("Pa | ");

    Serial.print("Temp: ")
    Serial.print(sdp.getTemperature());
    Serial.print("C\n");
  } else {
    Serial.print("Error in readSample(), ret = ")
    Serial.println(ret);
  }

  delay(500);
}
