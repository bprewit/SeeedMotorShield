/*
  SeeedMotorShield.h -- library for controlling Seeed Studio Motor Shield
  
  Original library     (0.1) by B. D. Prewit
*/

#ifndef SeeedMotorShield_h
#define SeeedMotorShield_h

typedef unsigned long ULONG;
typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef enum {dir_fwd, dir_rev} DIRECTION;
typedef enum {motor_a, motor_b} MOTOR;
typedef enum {
  d8 = 8,
  d9 = 9,
  d10 = 10,
  d11 = 11,
  d12 = 12,
  d13 = 13,
} SHIELD_PIN;

class MotorShield {
 public:

  MotorShield();

  ~MotorShield();

  void setSpeed(MOTOR motor, ULONG speed);

  void run(MOTOR motor, DIRECTION direction);
  void stop(MOTOR motor);

  int version(void);

 private:
  SHIELD_PIN pinI1;
  SHIELD_PIN pinI2;
  SHIELD_PIN enableA;

  SHIELD_PIN pinI3;
  SHIELD_PIN pinI4;
  SHIELD_PIN enableB;
};

#endif


