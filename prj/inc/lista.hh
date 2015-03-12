//lista.hh
#ifndef LISTA_HH
#define LISTA_HH

#include "struktura.hh"

struct pole{
  int wartosc;
  int *nastepna;
  pole(){wartosc=0; nastepna=NULL;}
};

class Lista: public Struktura{
  int *pole;
  virtual void push(int x);
};

#endif
