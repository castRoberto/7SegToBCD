#include "ConvertidorBCD.h"

ConvertidorBCD::ConvertidorBCD(TipoDisplay disp) {
  this->disp = disp;

  // DIRECCIONAMIENTO DE PUERTOS
  DDRD = 0b00000010;  // 0 = entrada, 1 = salida
  DDRB = 0b00011110;
}

void ConvertidorBCD::SevenSegRead() {
  this->puerto = ((PIND >> 1) | (PINB & (1<<PB0))); // Crear puerto (Leer estados 7 segmentos)
  
  // TIPO DE DISPLAY
  if(this->disp == ANODO) {
    invertir(); 
  }
}

void ConvertidorBCD::invertir() {
  this->puerto = ~this->puerto;
}

void ConvertidorBCD::ToBCD() {
  // MATEMATICA BOOLEANA
  this->A = ((c & !f) | (a & !e));                       // (C*~F)+(A*~E)
  this->B = (!b & e) | (a & !f);                         // (~B*E)+(A*~F)
  this->C = !b | (a & !d & !f) | (!a & f);               // (~B)+(A*~D*~F)+(~A*F)
  this->D = a & b && f & g;                              // (A*B*F*G)
}

void ConvertidorBCD::PrintBCD() {
  // IMPRIMIR RESULTADOS
  digitalWrite(9, !this->A);
  digitalWrite(10, !this->B);
  digitalWrite(11, !this->C);
  digitalWrite(12, !this->D);
}

TipoDisplay ConvertidorBCD::getDisplay() {
  return this->disp;
}
