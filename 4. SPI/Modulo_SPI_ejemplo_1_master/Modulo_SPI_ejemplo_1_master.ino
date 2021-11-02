/*
   Ejemplo 1 MASTER
   Crear un programa que permita intercambiar 4bits entre el master y el slave (Protocolo SPI).
   Los bits serán ingresados con un DipSwitch y serán visualizados en el otro dispositivo.
*/

void setup() {
  // 0 Entrada, 1 Salida
  // SCK=PB5 (1), MISO=PB4 (0), MOSI=PB3 (1), SS=PB2 (1)
  DDRB = 0b00101100;
  // El esclavo no se comunica al inicio
  PORTB |= 0b00000100;
  // Puerto C
  DDRC = 0b00001111;
  PORTC = 0b00000000;
  // Puerto D
  DDRD = 0b00000000;
  PORTD = 0b11110000;
  // Sin interrupcion, Habilito SPI, Mas significativo, Modo Master, Clock en bajo, Detección en flanco de subida, Preescaler 16
  SPCR = 0b01010001;
  // Sin velocidad doble
  SPSR = 0b00000000;
  delay(10);
  // Inicia comunicacion con el esclavo
  PORTB &= 0b11111011;
}

void loop() {
  // TX
  SPDR = PIND;
  while (!(SPSR & 0b10000000)); // Comprueba que termine de transmitir

  // RX
  while (!(SPSR & 0b10000000)); // Espera que complete la recepcion
  PORTC = SPDR >> 4;

  _delay_ms(100); // Retardo 100ms
}
