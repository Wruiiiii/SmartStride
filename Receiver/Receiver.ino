#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define buzzer 2
#define tensControlPin 7

RF24 radio(2, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  //Setup receiver
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  //Setup TENS and other output
  pinMode(buzzer, OUTPUT);
  pinMode(tensControlPin, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(tensControlPin, LOW);
}

void loop() {
  if (radio.available()) { //check if there is data to be received
    boolean boolStim = false;
    radio.read(&boolStim, sizeof(boolStim)); //read in

    if (boolStim) {
      digitalWrite(buzzer, HIGH); // Turn on buzzer (pin 2)
      digitalWrite(tensControlPin, HIGH); // Turn on TENS (pin 7)
    } else {
      digitalWrite(buzzer, LOW); // Turn off buzzer
      digitalWrite(tensControlPin, LOW); // Turn off TENS
    }
  }
  delay(100);
}