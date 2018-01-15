
#ifndef MADMAX_h
#define MADMAX_h

#include "Arduino.h"

class MadMax
{
  public:
    MadMax();
    void breakk();
    void forward();
    void backward();
  private:
    int _breakPinA;
    int _breakPinB;
    int _dirPinA;
    int _dirPinB;
    int _speedPinA;
    int _speedPinB;
    int _speed;
  
};

#endif
