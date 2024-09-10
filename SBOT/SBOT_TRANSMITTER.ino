#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Keypad.h>

// NRF24L01 setup
RF24 radio(9, 10);  // CE, CSN pins for the NRF24L01

// Address through which the data will be sent
const byte address[6] = "00001";

// Keypad setup
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, A1, A2, A3}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Buffer for text to send
String message = "";

void setup() {
  Serial.begin(9600);

  // Initialize NRF24L01
  radio.begin();
  radio.openWritingPipe(address); // Set the address
  radio.setPALevel(RF24_PA_MIN);  // RF power level
  radio.stopListening();          // Set as transmitter

  Serial.println("Ready to send data. Type on the keypad.");

  // Set up Keypad
}

void loop() {
  char key = keypad.getKey();  // Get keypress from the keypad

  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    // Check if the entered key is '#', the send button
    if (key == '#') {
      Serial.println("Sending message: " + message);
      char text[32];
      message.toCharArray(text, 32); // Convert String to char array
      radio.write(&text, sizeof(text)); // Send the message
      message = ""; // Clear the message buffer after sending
    } 
    else if (key == '*') {
      // Clear the message if '*' is pressed
      message = "";
      Serial.println("Message cleared");
    }
    else {
      // Append the pressed key to the message
      message += key;
    }
  }
}
