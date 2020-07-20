//#include ".h"

// #define STRINGIFY_(M) #M   (Donvierte a M en string)

void setup() {
  // DIRECCIONAMIENTO DE PUERTOS
  DDRD = 0b00000010;  // 0 = entrada, 1 = salida
  DDRB = 0b00011110;
}

void loop() {
  
}
