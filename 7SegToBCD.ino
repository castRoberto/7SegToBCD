#include "Cabecera.h"

unsigned char puerto;

TipoDisplay disp = CATODO;

// #define STRINGIFY_(M) #M   (Donvierte a M en string)

void setup() {
  // DIRECCIONAMIENTO DE PUERTOS
  DDRD = 0b00000010;  // 0 = entrada, 1 = salida
  DDRB = 0b00011110;
}

void loop() {
  puerto = ((PIND >> 1) | (PINB & (1<<PB0))); // Crear puerto (Leer estados 7 segmentos)

  // TIPO DE DISPLAY
  if(disp == ANODO) {
    invertir(); 
  }

  // MATEMATICA BOOLEANA
  bool A = ((c & !f) | (a & !e));                       // (C*~F)+(A*~E)
  bool B = (!b & e) | (a & !f);                         // (~B*E)+(A*~F)
  bool C = !b | (a & !d & !f) | (!a & f);               // (~B)+(A*~D*~F)+(~A*F)
  bool D = a & b && f & g;                              // (A*B*F*G)

  // IMPRIMIR RESULTADOS
  digitalWrite(9, !A);
  digitalWrite(10, !B);
  digitalWrite(11, !C);
  digitalWrite(12, !D);
}

void invertir() {
  puerto = ~puerto;
}
