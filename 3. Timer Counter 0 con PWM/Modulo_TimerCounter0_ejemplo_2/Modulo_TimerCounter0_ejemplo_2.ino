/*
   Ejemplo 4 PWM
   Crear un programa para generar una señal Fast PWM Invertida por el Pin OC0B con un ancho de pulso del 15%
*/

void setup() {
  DDRD = 0b00100000; //Puerto D: [5] OC0B Salida
  TCCR0A = 0b00110011; // [5:4] Modo invertido, [1:0] Fast PWM
  TCCR0B = 0b00000100; // [2:0] Preescaler 256
  OCR0B = 38; // Registro de comparación de salida para obtener un ancho de pulso del 15%
  _delay_ms(10);
}

void loop() {

}
