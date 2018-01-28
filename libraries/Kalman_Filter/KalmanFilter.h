
#ifndef _KALMAN_FILTER_1D_h
#define _KALMAN_FILTER_1D_h

class KalmanFilter {
public:
  KalmanFilter();
  float getMean();
  float getVariance();
  void setMean(float m);
  void setVariance(float P);
  void setModelVariance(float Q);
  void setMeasurementVariance(float R);
  void update(float measurement);
private:
  float m, R, P, Q;
};

#endif
