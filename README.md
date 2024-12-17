# Servo Motor Control with MPU6050 and NodeMCU ESP8266

This project demonstrates how to control a servo motor using the MPU6050 gyroscope and accelerometer sensor with a NodeMCU ESP8266. The servo angle is dynamically adjusted based on the tilt of the MPU6050 sensor, making it a great starting point for sensor-based control systems in robotics.

---

## Features

- Read gyroscope data from the MPU6050 sensor.
- Map gyroscope X-axis rotation to control the servo motor.
- Includes a calibration function to improve accuracy.

---

## Prerequisites

### **Hardware Requirements**

- NodeMCU ESP8266
- MPU6050 Gyroscope and Accelerometer Sensor
- Servo Motor
- Breadboard
- Jumper Wires
- External 5V Power Supply

### **Software Requirements**

- Arduino IDE
- Libraries:
  - Adafruit_MPU6050
  - Adafruit_Sensor
  - Servo

---

## Circuit Diagram

### **Connections**

#### **MPU6050 to NodeMCU**
- VCC → 3.3V
- GND → GND
- SCL → D1 (GPIO 5)
- SDA → D2 (GPIO 4)

#### **Servo Motor to NodeMCU**
- VCC → External 5V Power Supply
- GND → Common GND
- Signal → D4 (GPIO 2)

---

## Usage

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-repo-name>/servo-mpu6050-nodemcu.git
   ```
2. Open the Arduino IDE and load the code from the `servo_mpu6050.ino` file.
3. Install the required libraries using the Arduino Library Manager.
4. Connect the NodeMCU, MPU6050, and servo motor as per the circuit diagram.
5. Upload the code to the NodeMCU.
6. Open the Serial Monitor to view gyroscope readings and servo angle adjustments.

---

## Video Tutorial

Watch the step-by-step tutorial here: 
[![YouTube Video](https://img.youtube.com/vi/4NedQDT2nyw/0.jpg)](https://www.youtube.com/watch?v=4NedQDT2nyw)

---

## Blog Post

Read the detailed blog post with explanations and diagrams here: [Full Blog Tutorial](https://sanjaybora.vercel.app/blog/how-to-control-a-servo-motor-with-mpu6050-gyroscope-and-nodemcu)

---

## Code Overview

The Arduino sketch includes the following key features:

- **Sensor Initialization**: Sets up the MPU6050 sensor and configures ranges for accelerometer and gyroscope.
- **Servo Control**: Maps the gyroscope’s X-axis values to servo angles between 0° and 180°.
- **Calibration**: Eliminates gyroscope drift by averaging readings during a calibration phase.

---

## Troubleshooting

- **Servo not moving**: Ensure the servo motor is powered by an external 5V supply.
- **Sensor not detected**: Check the I2C connections (SCL, SDA) and ensure the MPU6050 is powered with 3.3V.
- **Erratic movements**: Recalibrate the gyroscope by restarting the system.

---

## License

This project is open-source and licensed under the MIT License. Feel free to use, modify, and share it!

