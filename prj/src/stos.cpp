//stos.cpp
#include "stos.hh"
/*!\file
 * \brief Zawiera definicje metod klasy Stos
 */

void Stos::push(int x){
  pole *nowe = new pole;
  nowe->wartosc = x;
  nowe->next=top;
  top=nowe;
}
    
void Stos::pop(){
  if(top == NULL)
    cerr<<"Stos jest pusty!"<<endl;
  else{
    pole *tmp = top;
    top=top->next;
    delete tmp;
  }
}

int Stos::size(){
 
  if(top == NULL)
    return 0;
  else{
    pole *wsk = top;
    int i=1;
    while(wsk->next){
      wsk=wsk->next;
      i++;
    }
  return i;
  }
}
