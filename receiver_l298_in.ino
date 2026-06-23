#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);   // CE, CSN
const byte address[6] = "00001";

char text[4];

// L298N pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void leftTurn() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightTurn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {

  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();

  Serial.println("Wheelchair Receiver Ready");
}

void loop() {

  if (radio.available()) {

    memset(text, 0, sizeof(text));

    radio.read(text, sizeof(text));

    Serial.print("Received: ");
    Serial.println(text);

    if (strcmp(text, "-X") == 0) {
      forward();
    }

    else if (strcmp(text, "+X") == 0) {
      backward();
    }

    else if (strcmp(text, "-Y") == 0) {
      leftTurn();
    }

    else if (strcmp(text, "+Y") == 0) {
      rightTurn();
    }

    // Neutral Head Position
    else if (strcmp(text, "---") == 0) {
      stopMotors();
    }

    // Emergency Stop
    else if (strcmp(text, "STP") == 0) {
      stopMotors();
      Serial.println("EMERGENCY STOP");
    }

    else {
      stopMotors();
    }
  }
}
