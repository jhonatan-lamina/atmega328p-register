/*
   Ejemplo 1
   Crear un programa que permita encender uno de 6 leds disponibles.
   El led será seleccionado ingresando su número mediante el puerto serial.
*/

void setup() {
  DDRC = 0b00111111; // A0 - A5 Salidas
  PORTC = 0b00000000; // Salidas en Bajo

  UCSR0A = 0b00000000;
  UCSR0B = 0b00011000; // Rx y Tx Habilitada
  UCSR0C = 0b00000110; // Asincrono, Sin Paridad, 1 bit de Parada
  UBRR0 = 103; // 9600 Baudios
  delay(10);
}

void loop() {
  // Rx
  if (UCSR0A & 0b10000000) { //Comprueba si existe un dato sin leer
    unsigned char dato = UDR0; // Añade los datos a la variable
    while (!(UCSR0A & 0b00100000)); // Espera hasta que el buffer este vacio
    // TX
    UDR0 = dato;
    // Control de Salidas
    if (dato == '1') {
      PORTC |= 0b00000001;
    } else {
      PORTC &= 0b11111110;
    }
    if (dato == '2') {
      PORTC |= 0b00000010;
    } else {
      PORTC &= 0b11111101;
    }
    if (dato == '3') {
      PORTC |= 0b00000100;
    } else {
      PORTC &= 0b11111011;
    }
    if (dato == '4') {
      PORTC |= 0b00001000;
    } else {
      PORTC &= 0b11110111;
    }
    if (dato == '5') {
      PORTC |= 0b00010000;
    } else {
      PORTC &= 0b11101111;
    }
    if (dato == '6') {
      PORTC |= 0b00100000;
    } else {
      PORTC &= 0b11011111;
    }
  }
}
