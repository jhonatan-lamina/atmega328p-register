/*
   Ejemplo 1 Timer/Counter 0
   Crear un programa para usar el Timer0 como contador de eventos externos(Pulsos generados por el botón)
   y mostrar el resultado en el Puerto C y D.
*/

uint8_t salida; // Declaracion de Variables

void setup() {
  DDRC = 0b11111111; // Puerto C: [5:0] Salidas
  DDRD = 0b00001100; // Puerto D: [3:2] Salidas
  PORTC = 0b00000000; // Salidas en LOW
  PORTD = 0b00000000; // Salidas en LOW
  TCCR0A = 0b00000000; // [7:6] OC0A Desabilitado, [5:4] OC0B Desabilitado, [1:0] Operacion normal
  TCCR0B = 0b00000111; // [2:0] Fuente de reloj ascendente externa en el Pin TO
  TCNT0 = 0b00000000; // Contador del timer comienza en 0
  _delay_ms(10);
}

void loop() {
  salida = TCNT0; // Coloco el valor del registro en la variable
  PORTC = (salida & 0b00111111); // Escribo los 6 primeros bits en el Puerto C
  PORTD = (salida & 0b11000000) >> 4; // Escribo los 2 bits restantes en el Puerto D
  _delay_ms(200); // Retardo 200ms
}
