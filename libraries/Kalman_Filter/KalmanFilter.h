
#ifndef _KALMAN_FILTER_1D_h
#define _KALMAN_FILTER_1D_h

class KalmanFilter {
public:
  KalmanFilter();
  float getMean();
  float getVariance();
  void setMean(float m);
  void setVariance(float P);
  void setMeasurementNoise();
  void setProcessNoise(); // TODO
  void update(float y);
private:
  float m, R, P, Q;
};

#endif
