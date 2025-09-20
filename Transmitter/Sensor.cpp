 #include "sensors.h"

// Pin definitions for the sensor
#define trigPin 6
#define echoPin 5

// This tells the compiler that sensorHeight is a global variable defined in the main .ino file
extern float sensorHeight; 

void setupSensors() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void calibrateSensor() {
  // Initial distance read to set baseline sensorHeight
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Calculate sensor height from ground when strapped to leg
  long initDur = pulseIn(echoPin, HIGH);
  sensorHeight = (initDur / 2.0) / 29.1;
  
  // Output the initial sensor height to log
  Serial.print("Baseline height: ");
  Serial.print(sensorHeight);
  Serial.println(" cm");
}

float readDistance() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo time and convert to distance
  long duration = pulseIn(echoPin, HIGH);
  return (duration / 2.0) / 29.1;
}