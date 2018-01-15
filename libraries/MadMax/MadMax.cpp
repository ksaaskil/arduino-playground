#include "Arduino.h"
#include "MadMax.h"

MadMax::MadMax(void)
{
  _dirPinA = 12;
  _breakPinA = 9;
  _speedPinA = 3;
  
  _dirPinB = 13;
  _breakPinB = 8;
  _speedPinB = 11;

  _speed = 100;
  
  pinMode(_dirPinA, OUTPUT);
  pinMode(_breakPinA, OUTPUT);
  pinMode(_speedPinA, OUTPUT);

  pinMode(_dirPinB, OUTPUT);
  pinMode(_breakPinB, OUTPUT);
  pinMode(_speedPinB, OUTPUT);
  
}

void MadMax::breakk()
{
  digitalWrite(_breakPinA, HIGH);
  digitalWrite(_breakPinB, HIGH);
}

void MadMax::forward() 
{
  digitalWrite(_breakPinA, LOW);
  digitalWrite(_breakPinB, LOW);
  digitalWrite(_dirPinA, HIGH);
  digitalWrite(_dirPinB, LOW);
  analogWrite(_speedPinA, _speed);
  analogWrite(_speedPinB, _speed);
}

void MadMax::backward()
{
  digitalWrite(_breakPinA, LOW);
  digitalWrite(_breakPinB, LOW);
  digitalWrite(_dirPinA, LOW);
  digitalWrite(_dirPinB, HIGH);
  analogWrite(_speedPinA, _speed);
  analogWrite(_speedPinB, _speed);
}

