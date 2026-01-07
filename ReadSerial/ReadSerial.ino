/**
 * @file Ex6_SerialLED.ino
 * @author
 * @date 2026-01-07
 * @brief Read a character from the Serial Monitor and control an LED with a switch-case.
 *
 * @details
 * This sketch listens for incoming bytes on the Serial port. When a byte is received,
 * it is stored in the variable @ref sendData and used in a switch statement.
 *
 * The program is intended to react to the characters:
 * - 'a' (ASCII 97)
 * - 'b' (ASCII 98)
 * - 'c' (ASCII 99)
 * - 'd' (ASCII 100)
 * - 'e' (ASCII 101)
 *
 * For each recognized case, it first turns the LED(s) off using @ref LEDSoff() and
 * then (for the 'a' case) turns the LED on. It also prints the received byte in
 * decimal form to the Serial Monitor.
 *
 * Any other character triggers the default case, which turns the LED off and prints
 * the received value.
 *
 * @note
 * - This code prints the incoming data as a decimal number (ASCII code). For example,
 *   sending 'a' prints 97.
 * - If your Serial Monitor is set to send newline/CR, you may also receive 10 (\\n)
 *   and/or 13 (\\r).
 * - The macro `P1` is defined as `D0`. On a classic Arduino Uno you typically use
 *   numbers like 2, 3, 4... instead of D0. `D0` is commonly used on some other boards.
 */

#include <SPI.h>  ///< SPI library included (not used in this sketch)

int sendData = 0; ///< Stores the latest received byte from Serial

/**
 * @brief LED output pin definition.
 *
 * @details
 * `P1` is a macro alias for pin `D0`. This sketch uses @ref P1 as the LED control pin.
 */
#define P1 D0

/**
 * @brief Arduino setup function.
 *
 * @details
 * Initializes Serial communication at 9600 baud and configures pin D0 as an output.
 */
void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
}

/**
 * @brief Turns all LED outputs off.
 *
 * @details
 * Sets pin @ref P1 LOW to ensure the LED is turned off.
 */
void LEDSoff() {
  digitalWrite(P1, LOW);
}

/**
 * @brief Arduino main loop.
 *
 * @details
 * - Checks if a byte is available on the Serial interface.
 * - Reads one byte with Serial.read() and stores it in @ref sendData.
 * - Uses a switch statement to compare the received value to expected ASCII codes.
 * - Prints the received value as a decimal number.
 *
 * Cases:
 * - 97 or 'a': turns LEDs off, then turns P1 on, prints 97
 * - 'b' (98): turns LEDs off, prints 98
 * - 99 or 'c': turns LEDs off, prints 99
 * - 100 or 'd': turns LEDs off, prints 100
 * - 101 or 'e': turns LEDs off, prints 101
 * - default: turns LEDs off, prints whatever was received
 */
void loop() {
  // Only run when at least one byte is available
  if (Serial.available() > 0) {
    sendData = Serial.read();  // Read one incoming byte

    switch (sendData) {
      case 97:  // ASCII for 'a'
        LEDSoff();
        digitalWrite(P1, HIGH);
        Serial.println(sendData, DEC);
        break;

      case 'b': // ASCII for 'b' (98)
        LEDSoff();
        Serial.println(sendData, DEC);
        break;

      case 99:  // ASCII for 'c'
        LEDSoff();
        Serial.println(sendData, DEC);
        break;

      case 100: // ASCII for 'd'
        LEDSoff();
        Serial.println(sendData, DEC);
        break;

      case 101: // ASCII for 'e'
        LEDSoff();
        Serial.println(sendData, DEC);
        break;

      default:
        LEDSoff();
        Serial.println(sendData, DEC);
        break;
    }
  }
}
