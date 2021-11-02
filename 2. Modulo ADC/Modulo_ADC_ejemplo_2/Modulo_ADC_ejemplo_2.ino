/*
   MODULO ADC
   Ejemplo 3
   Leer el Pin AD0 del Dispositivo y visualizar el valor de la lectura en el Puerto D y B.
*/

uint16_t valor_ADC; // Variable para guardar el valor del ADC

void setup() {
  DDRD = 0b11111100; // Puerto D: Salidas [7:2]
  DDRB = 0b00001111; // Puerto B: Salidas [3:0]
  PORTD = 0b00000000; // Salidas en LOW
  PORTB = 0b00000000; // Salidas en LOW
  ADMUX = 0b01000000; // [7:6] AVCC con condensador externo en AREF, [5] Justificacion derecha, [3:0] CanalADC0
  ADCSRA = 0b00000111; // [7]DeshabilitoAdc, [6]NoIniciaPrimeraConversión, [5]SinDisparoAutomatico, [4:3]SinInterrupciones, [2:0]Prescaler128-125kHz
  ADCSRB = 0b00000000; // [2:0] Funcionamiento Libre
  DIDR0 = 0b00000001; // Entrada digital ADC0 desactivada
  _delay_ms(10);
}

void loop () {
  ADCSRA |= 0b11000000; // [7] HabilitoAdc, [6] IniciaPrimeraConversión
  while (ADCSRA & 0b01000000); // [6] Espero que termine la conversion
  ADCSRA &= 0b00111111; // [7] DeshabilitoAdc
  valor_ADC = ADC; // Coloco los valores leidos por el adc en la variable
  PORTD = (valor_ADC & 0b0000111111) << 2; // Escribo los 6 primeros bits en el Puerto D
  PORTB = (valor_ADC & 0b1111000000) >> 6; // Escribo los 4 bits restantes en el Puerto B
  _delay_ms(100); // Retardo 100ms
}
