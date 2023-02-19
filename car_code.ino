
#include <IRremote.h>
#define IR_RECEIVE_PIN 10
#define IR_BUTTON_2 24
#define IR_BUTTON_4 8
#define IR_BUTTON_6 90
#define IR_BUTTON_8 82

int enA = 9;
int enB = 3;

int b1 = 4;
int b2 = 5;

int o1 = 7;
int o2 = 8;


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(o1, LOW);
  digitalWrite(o2, LOW);

}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_2: {
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(b1, HIGH);
        digitalWrite(b2, LOW);
        digitalWrite(o1, HIGH);
        digitalWrite(o2, LOW);
        delay(1000);
        digitalWrite(b1, LOW);
        digitalWrite(b2, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        break;
      }
      case IR_BUTTON_4: {
        analogWrite(enA, 255);
        analogWrite(enB, 180);
        digitalWrite(b1, HIGH);
        digitalWrite(b2, LOW);
        digitalWrite(o1, HIGH);
        digitalWrite(o2, LOW);
        delay(1000);
        digitalWrite(b1, LOW);
        digitalWrite(b2, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        break;
      }
      case IR_BUTTON_6: {
        analogWrite(enA, 180);
        analogWrite(enB, 255);
        digitalWrite(b1, HIGH);
        digitalWrite(b2, LOW);
        digitalWrite(o1, HIGH);
        digitalWrite(o2, LOW);
        delay(1000);
        digitalWrite(b1, LOW);
        digitalWrite(b2, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        break;
      }
      case IR_BUTTON_8: {
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(b1, LOW);
        digitalWrite(b2, HIGH);
        digitalWrite(o1, LOW);
        digitalWrite(o2, HIGH);
        delay(1000);
        digitalWrite(b1, LOW);
        digitalWrite(b2, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        break;
      }
      default: {
        
      }
    }
  }
}
