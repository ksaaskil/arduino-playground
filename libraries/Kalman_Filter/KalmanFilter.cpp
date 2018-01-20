
#include "KalmanFilter.h"

//TODO
KalmanFilter::KalmanFilter() {
  R = 0.03f;
  P = 0.03f;
  m = 0.0f;
}

float KalmanFilter::getMean() {
  return m;
}

float KalmanFilter::getVariance() {
  return P;
}

void KalmanFilter::setMean(m) {
  this -> m = m;
}

void KalmanFilter::setVariance(P) {
  this -> P = P;
}

void KalmanFilter::setMeasurementNoise(Q) {
  this -> Q = Q;
}

void KalmanFilter::setMeasurementNoise(r) {
  this -> r = R;
}

void KalmanFilter::update(float y) {
  m = m;
  P = P + Q;
  m = m + P / (P + R) * (y - m);
  P = P - P * P / (P + R);
}
