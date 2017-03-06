/*
 * IRremoteESP8266: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 Sept, 2015
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009, Copyright 2009 Ken Shirriff, http://arcfn.com
 */

#include <IRremoteESP8266.h>

int RECV_PIN = 2; //an IR detector/demodulatord is connected to GPIO pin 2

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // If the result is larger than a 32bit int, print the top half
    // then the lower half.
    // The Arduino framework doesn't play well printing 64bit values.
    if (results.value > 0xFFFFFFFFULL)
      Serial.print((uint32_t) (results.value >> 32), HEX);
    Serial.println((uint32_t) (results.value & 0xFFFFFFFFULL), HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
