/*
   Ejemplo 1
   Crear un código usando interrupciones para hacer parpadear los leds de acuerdo a las siguientes condiciones:
   Led 1 parpadea con un periodo de 200ms
   Led 2 parpadea con un periodo de 1000ms
   Led 3 parpadea con un periodo de 700ms
   Led 4 cambia de estado cada vez que se presiona el Pin INT0
*/

uint8_t contador_1 = 0;
uint8_t contador_2 = 0;
uint8_t contador_3 = 0;

void setup() {
  DDRC = 0b00001111; // Puerto C: [3:0] Salidas para los leds
  PORTC = 0b00000000; // Salidas en bajo

  cli(); // Deshabilito interrupciones hasta configurar

  // INTERRUPCION TIMER0
  TCCR0A = 0b00000010; // [7:6] OC0A Desabilitado, [5:4] OC0B Desabilitado, [1:0] Operacion normal
  TCCR0B = 0b00000101; // [2:0] Preescaler 1024
  TIMSK0 = 0b00000110; // [2:1]Interrupcion timer0 por comparacion A, B

  // INTERRUPCION EXTERNA
  EICRA = 0b00000010; // Interrupcion externa por flanco de bajada en el pin INT0
  EIMSK = 0b00000001; // Habilito interrupcion externa INTO
  EIFR = 0b00000000; // a 0 para detectar interrupciones en INT0

  sei(); // Habilito interrupciones

  OCR0A = 157; // Comparacion A cada 10ms
  OCR0B = 157; // Comparacion B cada 10ms
}

ISR(TIMER0_COMPA_vect) { // Interrupcion por comparacion A
  contador_1++; // Incremento la variable

  // Cambio de estado cada 200ms
  if (contador_1 == 20) { // Si la variable es igual a 20
    contador_1 = 0; // Reinica la variable
    PORTC ^= (1 << PINC0); // Cambia de estado el Pin
  }
}

ISR(TIMER0_COMPB_vect) { // Interrupcion por comparacion B
  contador_2++; // Incremento la variable
  contador_3++; // Incremento la variable

  // Cambio de estado cada 1000ms
  if (contador_2 == 100) { // Si la variable es igual a 10
    contador_2 = 0; // Reinica la variable
    PORTC ^= (1 << PINC1); // Cambia de estado el Pin
  }

  // Cambio de estado cada 700ms
  if (contador_3 == 70) { // Si la variable es igual a 10
    contador_3 = 0; // Reinica la variable
    PORTC ^= (1 << PINC2); // Cambia de estado el Pin
  }
}

ISR(INT0_vect) { // Interrupcion externa
  PORTC ^= (1 << PINC3); // Cambia de estado el Pin
}

void loop() {

}
