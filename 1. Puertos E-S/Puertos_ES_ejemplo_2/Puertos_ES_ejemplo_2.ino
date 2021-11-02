/*
   PUERTOS E/S
   Ejemplo 2
   Encender un Led D_x cada vez que se presione un Botón B_x.
*/

void setup() {
  DDRD = 0b11110000; // Puerto D: Salidas [7:4], Entradas [3:0]
  PORTD = 0b00001111; // Pull Up Activo en las Entradas
  _delay_ms(10);
}
void loop() {
  if (!(PIND & 0b00000001)) { // Si el estado del bit 1 es LOW
    PORTD |= 0b00011111; // Coloca el bit 4 en HIGH
  } else {
    PORTD &= 0b11101111; // Si no coloca el bit 4 en LOW
  }
  if (!(PIND & 0b00000010)) { // Si el estado del bit 2 es LOW
    PORTD |= 0b00101111; // Coloca el bit 5 en HIGH
  } else {
    PORTD &= 0b11011111; // Si no coloca el bit 5 en LOW
  }
  if (!(PIND & 0b00000100)) { // Si el estado del bit 3 es LOW
    PORTD |= 0b01001111; // Coloca el bit 6 en HIGH
  } else {
    PORTD &= 0b10111111; // Si no coloca el bit 6 en LOW
  }
  if (!(PIND & 0b00001000)) { // Si el estado del bit 4 es LOW
    PORTD |= 0b10001111; // Coloca el bit 7 en HIGH
  } else {
    PORTD &= 0b01111111; // Si no coloca el bit 7 en LOW
  }
  _delay_ms(100); // Retardo 100ms
}
