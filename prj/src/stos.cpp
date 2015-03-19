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

bool Stos::wykonaj_program(char* nazwa_pliku, int ilosc_danych){
  int tmp;
  plik_we.open(nazwa_pliku);
  if(plik_we.good()==false){
    cerr<<"Blad odczytu pliku!"<<endl;
    return false;
  }
  plik_we >> rozmiar_tab;
  for(int i=0;i<ilosc_danych;i++){
    plik_we >> tmp;
    push(tmp);
  }
  plik_we.close();
  return true;
}

void Stos::wyczysc_dane(int ile){
  for(int i=0;i<ile;i++)
    pop();
}
