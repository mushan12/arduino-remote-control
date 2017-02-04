/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void translateIR() {
  switch(results.value) {
    case 0xC101E57B:
      Serial.println(0);
      break;
    case 0xFF30CF:
      Serial.println(1);
      break;
    case 0xFF18E7:
      Serial.println(2);
      break;
    case 0xFF7A85:
      Serial.println(3);
      break;
    case 0x8C22657B:
      Serial.println(4);
      break;
    case 0x488F3CBB:
      Serial.println(5);
      break;
    case 0x449E79F:
      Serial.println(6);
      break;
    case 0x32C6FDF7:
      Serial.println(7);
      break;
    case 0x1BC0157B:
      Serial.println(8);
      break;
    case 0x3EC3FC1B:
      Serial.println(9);
      break;
    default:
      Serial.println(results.value, HEX);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    translateIR();
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
