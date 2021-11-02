/*
   Ejemplo 1
   Crear un programa que permita grabar un número de 4 bits ingresado usando el DipSwitch en la Memoria EEPROM luego de presionar el mismo.
   El valor almacenado se debe mostrar en los leds cada vez que el dispositivo se reinicia.
*/

#include <avr/eeprom.h>

void setup() {
  DDRB = 0b00000000; // Entrada Botton Pin 8
  PORTB = 0b00000001; // Pull-Up Botton

  DDRD = 0b00000000; // Entradas para el switch
  PORTD = 0b11110000; // Pull-Up switch

  DDRC = 0b00001111; // Salidas para los leds

  // Escribo en el puerto C el valor de la dirección 64 de la EEPROM.
  PORTC = eeprom_read_byte((const uint8_t*)64);

  delay(10);
}

void loop() {
  if ((PINB & 0b00000001) == 0) { // Si el estado del bit 1 es LOW
    while (!(PIND & 0b00000001)); // Espero hasta que el estado del bit 1 sea HIGH
    // Actualizo el valor del byte 64 con el valor del Puerto D
    eeprom_update_byte((uint8_t*)64, (PIND >> 4));
  }
  delay(100);// Retardo 100ms
}
