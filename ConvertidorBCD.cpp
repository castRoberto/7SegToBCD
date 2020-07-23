#include "ConvertidorBCD.h"

ConvertidorBCD::ConvertidorBCD(TipoDisplay disp) {
  this->disp = disp;

  // DIRECCIONAMIENTO DE PUERTOS
  DDRD = 0b00000010;  // 0 = entrada, 1 = salida
  DDRB = 0b00111100;
}

void ConvertidorBCD::SevenSegRead() {
  this->puerto = ((PIND>>2) & 63) | ((PINB & (1<<PB1)) << 6) | ((PINB & (1<<PB0)) << 6); // Crear puerto (Leer estados 7 segmentos)
  
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
  this->A = ((c & !f) | (a & !e)) | h;                       // (C*~F)+(A*~E)
  this->B = ((!b & e) | (a & !f)) | h;                         // (~B*E)+(A*~F)
  this->C = !b | (a & !d & !f) | (!a & f);               // (~B)+(A*~D*~F)+(~A*F)
  this->D = (a & b & f & g) | h;                              // (A*B*F*G)
}

void ConvertidorBCD::PrintBCD() {
  // IMPRIMIR RESULTADOS
  digitalWrite(10, !this->A);
  digitalWrite(11, !this->B);
  digitalWrite(12, !this->C);
  digitalWrite(13, !this->D);
}

TipoDisplay ConvertidorBCD::getDisplay() {
  return this->disp;
}
