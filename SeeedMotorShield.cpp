/*
  SeedMotorShield.cpp - - library for Seeed Motor Shield
  Original library     (0.1) B. D. Prewit 08/2013
*/


#include "arduPi.h"
#include "SeeedMotorShield.h"
#include "time.h"

clock_t msec(void)
{
  return ((clock()*1000/CLOCKS_PER_SEC));
}

/*
  version() returns the version of the library:
*/
int MotorShield::version(void)
{
  return 100;
}

// constructor
MotorShield::MotorShield()
{
  pinI1 = d8;
  pinI2 = d11;
  enableA = d9;

  pinI3 = d12;
  pinI4 = d13;
  enableB = d10;

  pinMode(pinI1, OUTPUT);
  pinMode(pinI2, OUTPUT);
  pinMode(enableA, OUTPUT);
        
  pinMode(pinI3, OUTPUT);
  pinMode(pinI4, OUTPUT);
  pinMode(enableB, OUTPUT);
}

// destructor:
MotorShield::~MotorShield()
{
}

// set motor speed
void MotorShield::setSpeed(MOTOR motor, ULONG what_speed)
{
}

// run motor in dir
void MotorShield::run(MOTOR motor, DIRECTION direction)
{
  UINT enable, pin1, pin2;

  switch (motor) {
  case motor_a:
    enable = enableA;
    pin1 = pinI1;
    pin2 = pinI2;
    break;

  case motor_b:
    enable = enableB;
    pin1 = pinI3;
    pin2 = pinI4;
    break;

  default:
    return;
    break;
  }
  
  switch(direction) {
  case dir_rev:
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(enable, HIGH);
    break;

  case dir_fwd:
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(enable, HIGH);
    break;

  default:
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(enable, LOW);
    break;
  }
}

  
void MotorShield::stop(MOTOR motor)
{
  UINT enable, pin1, pin2;

  switch (motor) {
  case motor_a:
    enable = enableA;
    pin1 = pinI1;
    pin2 = pinI2;
    break;
  case motor_b:
    enable = enableB;
    pin1 = pinI3;
    pin2 = pinI4;
    break;
  default:
    break;
  }
  
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(enable, LOW);
}

