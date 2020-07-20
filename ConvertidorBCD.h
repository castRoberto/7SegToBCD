#ifndef CONVERTIDOR_BCD_H
#define CONVERTIDOR_BCD_H
#include <Arduino.h>
#include "enum.h"
#include "macros.h"

class ConvertidorBCD {
  private:
    unsigned char puerto;
    TipoDisplay disp;
    bool A, B, C, D;
    void invertir();
  public:
    ConvertidorBCD(TipoDisplay disp);
    void SevenSegRead();
    void ToBCD();
    void PrintBCD();
    TipoDisplay getDisplay();
};

#endif // CONVERTIDOR_BCD_H
