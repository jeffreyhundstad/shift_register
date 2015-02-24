/* shift_register
 *
 * Demo of the 74HC595, Arduino shiftOut and arrays
 * by: Jeffrey E. Hundstad <we0a@arrl.net> 2015-02-23
 */

/* PINS */
const byte dataPin = 11; // 74HC595-Pin-14 SER (serial data)
const byte clockPin = 13; // 74HC595-Pin-11 SRCLK (serial clock)
const byte latchPin = 7; // 74HC595-Pin-12 RCLK (register latch)
// 74HC595-Pin-8 GND
// 74HC595-Pin-16 VCC
// 74HC595-Pin-13 OE (Output Enable, LOW to enable)

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
}

const byte animation[] = {0b00000001,
                          0b00000010,
                          0b00000100
                         };


void loop() {
  for (byte sequence = 0; sequence < 3; sequence++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, animation[sequence]);
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
