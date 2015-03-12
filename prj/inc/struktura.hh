//struktura.hh
#ifndef STRUKTURA_HH
#define STRUKTURA_HH

#include "program.hh"

/*!\file
 * \brief Definicja klasy Struktura
 */

/*!
 * \brief Modeluje klase Struktura
 *
 * Klasa Struktura zawiere zmienne oraz metody wspolne dla wszystkich 
 * implementowanych struktur.
 */
class Struktura: public Program{
protected:
  virtual void push(int x)=0;
  virtual void pop()=0;
  virtual int size()=0;
};

#endif
