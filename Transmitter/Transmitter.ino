#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "sensors.h"

// Global variables
float sensorHeight; 
float currentDistance;
bool shouldStimulate = false;

// RF Communication setup
RF24 radio(2, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  //Start logging
  Serial.begin(9600);

  // Setup hardware modules
  setupSensors();
  
  //Setup transmitter
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  // Get the initial baseline distance from the ground
  calibrateSensor();
  
  Serial.println("System Initialized");
}

void loop() {
  // 1. Read the distance from the sensor module
  currentDistance = readDistance();

  //Print distance out to log
  Serial.print("Distance: ");
  Serial.print(currentDistance);
  Serial.println(" cm");

  // 2. Decide if stimulation is needed
  if (currentDistance >= sensorHeight + 14) {
    shouldStimulate = true;
  } else {
    shouldStimulate = false;
  }

  // 3. Send the decision to the receiver
  radio.write(&shouldStimulate, sizeof(shouldStimulate));
  
  delay(1000);
}