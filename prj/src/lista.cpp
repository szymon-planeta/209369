//lista.cpp
#include "lista.hh"

/*!\file 
 * \brief Zawiera definicje metod klasy Lista
 */
void Lista::push(int x){
  pole *nowe = new pole;
  nowe->wartosc = x;
  if(first == NULL){
    first = nowe;
  }
  else{
    pole *wsk = first;
    while(wsk->next)
      wsk=wsk->next;
    wsk->next = nowe;
    nowe->next = NULL;
  }
}

void Lista::pop(){}

int Lista::size(){return 0;}
