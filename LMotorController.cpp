#include "LMotorController.h"

LMotorController::LMotorController(int ENA, int IN1, int IN2,
                                   int ENB, int IN3, int IN4,
                                   double leftSpeedFactor, double rightSpeedFactor) {
    _ENA = ENA; _IN1 = IN1; _IN2 = IN2;
    _ENB = ENB; _IN3 = IN3; _IN4 = IN4;
    _leftSpeedFactor  = constrain(leftSpeedFactor,  0.0, 1.0);
    _rightSpeedFactor = constrain(rightSpeedFactor, 0.0, 1.0);

    pinMode(_ENA, OUTPUT); pinMode(_IN1, OUTPUT); pinMode(_IN2, OUTPUT);
    pinMode(_ENB, OUTPUT); pinMode(_IN3, OUTPUT); pinMode(_IN4, OUTPUT);

    stopMoving();
}

void LMotorController::moveMotor(int dirPin1, int dirPin2, int pwmPin, int speed, double factor) {
    int pwmValue = (int)(abs(speed) * factor);
    pwmValue = constrain(pwmValue, 0, 255);

    if (speed > 0) {
        digitalWrite(dirPin1, HIGH);
        digitalWrite(dirPin2, LOW);
    } else {
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, HIGH);
    }

    analogWrite(pwmPin, pwmValue);
}

void LMotorController::move(int speed, int minAbsSpeed) {
    if (abs(speed) < minAbsSpeed) {
        stopMoving();
        return;
    }

    moveMotor(_IN1, _IN2, _ENA, speed, _leftSpeedFactor);
    moveMotor(_IN3, _IN4, _ENB, speed, _rightSpeedFactor);
}

void LMotorController::stopMoving() {
    digitalWrite(_IN1, LOW); digitalWrite(_IN2, LOW); analogWrite(_ENA, 0);
    digitalWrite(_IN3, LOW); digitalWrite(_IN4, LOW); analogWrite(_ENB, 0);
}
