//stos.hh
#ifndef STOS_HH
#define STOS_HH
#include "program.hh"
class Stos: public Program{

public:
  virtual void push(int wartosc);
  virtual void pop();
  virtual int size();
};

#endif
