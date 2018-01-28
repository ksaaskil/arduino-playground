/****************************************************************
Uses the SparkFun ZX distance and gesture sensor and its library:
https://github.com/sparkfun/SparkFun_ZX_Distance_and_Gesture_Sensor_Arduino_Library
****************************************************************/

#include <Wire.h>
#include <ZX_Sensor.h>
#include <KalmanFilter.h>

// Kalman filter
const float MEAN_0 = 50.0;
const float VARIANCE_0 = 100.0;
const float MEASUREMENT_VARIANCE = 10.0;
const float MODEL_VARIANCE = 10.0;

const int ZX_ADDR = 0x10;  // ZX Sensor I2C address

uint8_t z_pos;

KalmanFilter kf = KalmanFilter();
ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);

void setup() {

  kf.setMean(MEAN_0);
  kf.setVariance(VARIANCE_0);
  kf.setModelVariance(MODEL_VARIANCE);
  kf.setMeasurementVariance(MEASUREMENT_VARIANCE);

  Serial.begin(9600);
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
      kf.update(z_pos);
      Serial.print("Z position: ");
      Serial.print(z_pos);
      Serial.print(",");
      Serial.println(kf.getMean());
    }
  }
}
