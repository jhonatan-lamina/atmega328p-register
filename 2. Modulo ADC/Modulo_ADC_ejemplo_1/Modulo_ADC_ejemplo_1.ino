/*
   MOSULO ADC
   Ejemplo 1
   Leer el Pin AD0 del Dispositivo y enviar el valor de la Lectura al PC mediante el Puerto Serial.
*/

uint16_t valor_ADC; // Variable para guardar el valor del ADC

void setup() {
  Serial.begin(9600); // Inicializa la Comunicación Serial a 9600 Baudios
  ADMUX = 0b01000000; // [7:6] AVCC con condensador externo en AREF, [5] Justificacion derecha, [3:0] CanalADC0
  ADCSRA = 0b00000111; // [7]DeshabilitoAdc, [6]NoIniciaPrimeraConversión, [5]SinDisparoAutomatico, [4:3]SinInterrupciones, [2:0]Prescaler128=125kHz
  ADCSRB = 0b00000000; // [2:0] Funcionamiento Libre
  DIDR0 = 0b00000001; // Entrada digital ADC0 desactivada
  _delay_ms(10);
}

void loop() {
  ADCSRA |= 0b11000000; // [7] HabilitoAdc, [6] IniciaPrimeraConversión
  while (ADCSRA & 0b01000000); // [6] Espero que termine la conversion
  ADCSRA &= 0b00111111; // [7] DeshabilitoAdc
  valor_ADC = ADC; // Coloco los valores leidos por el adc en la variable
  Serial.println(valor_ADC); // Envio los valores de la variable por el puerto serial
  _delay_ms(200); // Retardo 200ms
}
