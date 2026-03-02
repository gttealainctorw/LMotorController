# LMotorController

Arduino library for controlling dual DC motors via an **L298N** motor driver module. Designed for self-balancing robots using PID control.

## Features

- Independent speed correction factor per motor (compensates for motor asymmetry)
- Minimum speed threshold to prevent motor jitter at near-zero PID outputs
- Clean stop function
- Compatible with AVR (Uno, Nano, Mega), ESP32, ESP8266

## Wiring (L298N)

| L298N Pin | Arduino Pin | Description          |
|-----------|-------------|----------------------|
| ENA       | 5 (PWM)     | Left motor speed     |
| IN1       | 7           | Left motor dir 1     |
| IN2       | 6           | Left motor dir 2     |
| ENB       | 10 (PWM)    | Right motor speed    |
| IN3       | 8           | Right motor dir 1    |
| IN4       | 9           | Right motor dir 2    |

## Installation

### Opción A — Desde GitHub (manual)

1. En este repositorio click en el botón verde **"Code"** → **"Download ZIP"**
2. Abre el Arduino IDE
3. Ve a **Sketch** → **Include Library** → **Add .ZIP Library...**
4. Selecciona el ZIP descargado
5. Listo, ya puedes usar `#include <LMotorController.h>`

### Opción B — Manual (copiar carpeta)

1. Descarga o clona este repositorio
2. Copia la carpeta `LMotorController` a tu directorio de librerías de Arduino:
   - Windows: `Documents/Arduino/libraries/`
   - Linux/Mac: `~/Arduino/libraries/`
3. Reinicia el Arduino IDE

## Usage

```cpp
#include <LMotorController.h>

// LMotorController(ENA, IN1, IN2, ENB, IN3, IN4, leftSpeedFactor, rightSpeedFactor)
LMotorController motors(5, 7, 6, 10, 8, 9, 0.7, 0.6);

// Move forward/backward based on PID output (-255 to 255)
motors.move(output, MIN_ABS_SPEED);

// Stop
motors.stopMoving();
```

### Constructor Parameters

| Parameter         | Type   | Description                                         |
|-------------------|--------|-----------------------------------------------------|
| ENA               | int    | PWM pin for left motor                              |
| IN1               | int    | Direction pin 1 for left motor                      |
| IN2               | int    | Direction pin 2 for left motor                      |
| ENB               | int    | PWM pin for right motor                             |
| IN3               | int    | Direction pin 1 for right motor                     |
| IN4               | int    | Direction pin 2 for right motor                     |
| leftSpeedFactor   | double | Speed multiplier for left motor (0.0 – 1.0)        |
| rightSpeedFactor  | double | Speed multiplier for right motor (0.0 – 1.0)       |

### `move(int speed, int minAbsSpeed)`

| Parameter     | Description                                                       |
|---------------|-------------------------------------------------------------------|
| `speed`       | PID output value (-255 to 255). Positive = forward, Negative = backward |
| `minAbsSpeed` | Minimum absolute speed. Motors stop if `abs(speed) < minAbsSpeed` |

## Self-Balancing Robot Example

See [`examples/SelfBalancingRobot/`](examples/SelfBalancingRobot/SelfBalancingRobot.ino)

Required libraries for the example:
- [PID_v1](https://github.com/br3ttb/Arduino-PID-Library) — Brett Beauregard
- [i2cdevlib (MPU6050 + I2Cdev)](https://github.com/jrowberg/i2cdevlib) — Jeff Rowberg

## License

MIT License — free to use, modify and distribute.
