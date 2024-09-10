#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NRF24L01 setup
RF24 radio(5, 15);  // CE, CSN pins for the NRF24L01

// Address for the receiver to listen on
const byte address[6] = "00001";

void setup() {
  Serial.begin(115200);

  // Initialize NRF24L01
  radio.begin();
  radio.openReadingPipe(0, address); // Set the same address as the transmitter
  radio.setPALevel(RF24_PA_MIN);     // RF power level
  radio.startListening();            // Set as receiver

  Serial.println("Waiting for message...");
}

void loop() {
  if (radio.available()) {
    char text[32] = {0};
    radio.read(&text, sizeof(text)); // Read incoming message

    // Display the received message
    Serial.print("Received message: ");
    Serial.println(text);
  }
}
