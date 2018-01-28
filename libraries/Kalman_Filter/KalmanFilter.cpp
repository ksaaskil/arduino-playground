
#include "KalmanFilter.h"

//TODO
KalmanFilter::KalmanFilter() {
  R = 0.03f;
  P = 0.03f;
  Q = 0.03f;
  m = 0.0f;
}

float KalmanFilter::getMean() {
  return m;
}

float KalmanFilter::getVariance() {
  return P;
}

void KalmanFilter::setMean(float m) {
  this -> m = m;
}

void KalmanFilter::setVariance(float P) {
  this -> P = P;
}

void KalmanFilter::setModelVariance(float Q) {
  this -> Q = Q;
}

void KalmanFilter::setMeasurementVariance(float R) {
  this -> R = R;
}

void KalmanFilter::update(float measurement) {
  m = m;
  P = P + Q;
  m = m + P / (P + R) * (measurement - m);
  P = P - P * P / (P + R);
}
