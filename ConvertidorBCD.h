#ifndef CONVERTIDOR_BCD_H
#define CONVERTIDOR_BCD_H
#include <Arduino.h>
#include "enum.h"

class ConvertidorBCD {
  private:
    unsigned char puerto;
    TipoDisplay disp;
    void invertir();
  public:
    ConvertidorBCD(TipoDisplay disp);
};

#endif // CONVERTIDOR_BCD_H
