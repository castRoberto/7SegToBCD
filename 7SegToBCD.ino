#include "ConvertidorBCD.h"

ConvertidorBCD Display(CATODO);

void setup() {
  // DIRECCIONAMIENTO DE PUERTOS
  DDRD = 0b00000010;  // 0 = entrada, 1 = salida
  DDRB = 0b00111100;
}

void loop() {
  Display.SevenSegRead();
  Display.ToBCD();
  Display.PrintBCD();
}

// #define STRINGIFY_(M) #M   (Donvierte a M en string)
