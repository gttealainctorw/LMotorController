#ifndef LMotorController_h
#define LMotorController_h

#include <Arduino.h>

/**
 * LMotorController - Dual DC Motor Controller Library
 * Compatible with L298N motor driver module
 * Designed for self-balancing robots using PID control
 *
 * Wiring:
 *   ENA -> PWM pin (left motor speed)
 *   IN1, IN2 -> Direction pins (left motor)
 *   ENB -> PWM pin (right motor speed)
 *   IN3, IN4 -> Direction pins (right motor)
 */
class LMotorController {
  public:
    /**
     * Constructor
     * @param ENA  PWM pin for left motor
     * @param IN1  Direction pin 1 for left motor
     * @param IN2  Direction pin 2 for left motor
     * @param ENB  PWM pin for right motor
     * @param IN3  Direction pin 1 for right motor
     * @param IN4  Direction pin 2 for right motor
     * @param leftSpeedFactor  Speed multiplier for left motor  (0.0 - 1.0)
     * @param rightSpeedFactor Speed multiplier for right motor (0.0 - 1.0)
     */
    LMotorController(int ENA, int IN1, int IN2,
                     int ENB, int IN3, int IN4,
                     double leftSpeedFactor, double rightSpeedFactor);

    /**
     * Move both motors based on PID output
     * @param speed       PID output value (-255 to 255). Positive = forward, Negative = backward
     * @param minAbsSpeed Minimum absolute speed threshold. Below this value motors stop.
     */
    void move(int speed, int minAbsSpeed);

    /**
     * Immediately stop both motors
     */
    void stopMoving();

  private:
    int _ENA, _IN1, _IN2;
    int _ENB, _IN3, _IN4;
    double _leftSpeedFactor;
    double _rightSpeedFactor;

    /**
     * Internal helper to drive a single motor
     * @param dirPin1    Direction pin 1
     * @param dirPin2    Direction pin 2
     * @param pwmPin     PWM (enable) pin
     * @param speed      Speed value (-255 to 255)
     * @param factor     Speed correction factor (0.0 - 1.0)
     */
    void moveMotor(int dirPin1, int dirPin2, int pwmPin, int speed, double factor);
};

#endif
