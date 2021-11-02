/*
   PUERTOS E/S
   Ejemplo 1
   Activar y desactivar 4 leds cada 100ms.
*/

void setup() {
  DDRD = 0b11110000; // Puerto D: Salidas [7:4]
  PORTD = 0b00000000; // Salidas en Bajo
  _delay_ms(10);
}

void loop() {
  PORTD = 0b11110000; //Salidas en estado HIGH
  _delay_ms(100); // Retardo 100ms
  PORTD = 0b00000000; //Salidas en estado LOW
  _delay_ms(100); // Retardo 100ms
}
