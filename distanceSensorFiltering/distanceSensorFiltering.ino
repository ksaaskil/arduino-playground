/****************************************************************
Uses the SparkFun ZX distance and gesture sensor and its library:
https://github.com/sparkfun/SparkFun_ZX_Distance_and_Gesture_Sensor_Arduino_Library
****************************************************************/

#include <Wire.h>
#include <ZX_Sensor.h>
#include <KalmanFilter.h>

const int ZX_ADDR = 0x10;  // ZX Sensor I2C address

ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);
uint8_t z_pos;

void setup() {
  Serial.begin(9600);
  
  // Initialize
  if (zx_sensor.init()) {
    Serial.println("Initialized the sensor");
  } else {
    Serial.println("Something went wrong during ZX Sensor init!");
    exit(0);
  }
}

void loop() {
  
  if (zx_sensor.positionAvailable()) {
    z_pos = zx_sensor.readZ();
    if ( z_pos != ZX_ERROR ) {
      Serial.print("Z position: ");
      Serial.println(z_pos);
      //Serial.println(40.0);
    }
  }
}
