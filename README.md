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

### Option A — From GitHub (Manual Install)

1. In this repository, click the green **Code** button → **Download ZIP**
2. Open the **Arduino IDE**
3. Go to **Sketch → Include Library → Add .ZIP Library...**
4. Select the downloaded ZIP file
5. Done! You can now use:

    #include <LMotorController.h>

---

### Option B — Manual Installation (Copy Folder)

1. Download or clone this repository
2. Copy the **LMotorController** folder into your Arduino libraries directory:

   - **Windows:** Documents/Arduino/libraries/
   - **Linux / macOS:** ~/Arduino/libraries/

3. Restart the **Arduino IDE**

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

## License

MIT License — free to use, modify and distribute.
