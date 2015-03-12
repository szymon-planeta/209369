//stos.hh
#ifndef STOS_HH
#define STOS_HH
#include "struktura.hh"
class Stos: public Struktura{

public:
  virtual void push(int wartosc);
  virtual void pop();
  virtual int size();
};

#endif
