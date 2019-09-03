#include <Arduino.h>

#define HDR (*((volatile unsigned char *)0xE0))
#define HDR5 5
#define HDR4 4
#define HDR3 3
#define HDR2 2
#define HDR1 1
#define HDR0 0

#define PORTF (*((volatile unsigned char *)0x14))
#define DDRF  (*((volatile unsigned char *)0x13))

// #include <avr/io.h> // Contains all the I/O Register Macros
// #include <util/delay.h> // Generates a Blocking Delay

// void udelay (char i) {
// __asm__ volatile ("1: subi %0, 0x01\n  brne 1b" : "+rm"(i) : : );
// }

void setup() {
  DDRD = (1 << 5) | (1 << 6);
  // DDRF = (1 << 1) | (1 << 2);
  HDR = 0xff;
}

void loop() {
  PORTD = 1 << 6;
  // PORTF = 1 << 1;
  delay(1);
  PORTF = 0;
  delay(250);
  PORTD = 1 << 5;
  // PORTF = 1 << 2;
  delay(1);
  PORTF = 0;
  delay(250);
}
