/*
   Ejemplo 1 SLAVE
   Crear un programa que permita intercambiar 4bits entre el master y el slave (Protocolo SPI).
   Los bits serán ingresados con un DipSwitch y serán visualizados en el otro dispositivo.
*/

void setup() {
  // 0 Entrada, 1 Salida
  // SCK=PB5 (0), MISO=PB4 (1), MOSI=PB3 (0), SS=PB2 (0)
  DDRB = 0b00010000;
  // Puerto C
  DDRC = 0b00001111;
  PORTC = 0b00000000;
  // Puerto D
  DDRD = 0b00000000;
  PORTD = 0b11110000;
  // Sin interrupcion, Habilito SPI, Mas significativo primero, Modo Esclavo
  SPCR = 0b01000000;
  // Sin velocidad doble
  SPSR = 0b00000000;
  delay(10);
}

void loop() {
  while (PINB & 0b00000100); // Espera hasta que exista comunicacion

  // RX
  while (!(SPSR & 0b10000000)); // Espera que complete la recepcion
  PORTC = SPDR >> 4;

  // TX
  SPDR = PIND;
  while (!(SPSR & 0b10000000)); // Comprueba que termine de transmitir
}
