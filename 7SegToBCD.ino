#include "ConvertidorBCD.h"

ConvertidorBCD Display(CATODO);

void setup() {
}

void loop() {
  Display.SevenSegRead();
  Display.ToBCD();
  Display.PrintBCD();
}

// #define STRINGIFY_(M) #M   (Donvierte a M en string)
