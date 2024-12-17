#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>

Adafruit_MPU6050 mpu;
Servo myServo;

const int servoPin = 2; // Define the pin for the servo signal
int servoAngle = 90;    // Initialize the servo at 90 degrees

float gyroX_offset = 0; // Offset for gyro X-axis

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("Adafruit MPU6050 Servo Control with Calibration!");

  // Initialize the MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  // Configure MPU6050 ranges
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // Attach the servo and set initial position
  myServo.attach(servoPin);
  myServo.write(servoAngle);

  // Calibration process
  Serial.println("Calibrating gyroscope... Please keep the sensor still.");
  gyroX_offset = calibrateGyro();
  Serial.print("Calibration complete. Gyro X offset: ");
  Serial.println(gyroX_offset);

  Serial.println("Setup complete!\n");
  delay(100);
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Read gyroscope rotation along X-axis and remove the offset
  float gyroX = g.gyro.x - gyroX_offset;

  // Map the gyroscope X-axis value to servo angles (0-180°)
  servoAngle += gyroX * 10; // Adjust the sensitivity with this multiplier
  servoAngle = constrain(servoAngle, 0, 180);

  // Write the angle to the servo
  myServo.write(servoAngle);

  /* Print out the values */
  Serial.print("Gyro X: ");
  Serial.print(gyroX);
  Serial.print(" rad/s | Servo Angle: ");
  Serial.println(servoAngle);

  delay(50); // Small delay for stability
}

// Function to calibrate gyro X-axis for 5 seconds
float calibrateGyro() {
  const int calibrationTime = 5000; // Calibration time in milliseconds
  int sampleCount = 0;
  float gyroX_sum = 0;

  unsigned long startTime = millis();
  while (millis() - startTime < calibrationTime) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    gyroX_sum += g.gyro.x;
    sampleCount++;

    delay(10); // Small delay between samples
  }

  return gyroX_sum / sampleCount; // Return the average gyro X-axis offset
}

