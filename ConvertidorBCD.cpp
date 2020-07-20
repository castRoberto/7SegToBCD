#include "ConvertidorBCD.h"
#include "enum.h"

ConvertidorBCD::ConvertidorBCD(TipoDisplay disp) {
  this->disp = disp;

  // DIRECCIONAMIENTO DE PUERTOS
  DDRD = 0b00000010;  // 0 = entrada, 1 = salida
  DDRB = 0b00011110;
}

void ConvertidorBCD::invertir() {
  this->puerto = ~this->puerto;
}
