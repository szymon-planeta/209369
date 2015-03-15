//lista.hh
#ifndef LISTA_HH
#define LISTA_HH

#include "struktura.hh"

struct pole{
  int wartosc;
  pole *next;
  pole(){wartosc=0; next=NULL;}
};

class Lista: public Struktura{
  public: //zmien zmien
  pole *first;
  Lista(){
    first = NULL;
  }
public:
  void push(int x);
  void pop();
  int size();
};

#endif
