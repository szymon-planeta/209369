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

void Lista::pop(){
  if(first == NULL){
    cerr<<"Lista jest pusta!"<<endl;
  }
  else{
    pole *wsk = first;
    pole *prev = NULL;
    while(wsk->next){
      prev=wsk;
      wsk=wsk->next;
    }
    if(prev==NULL){
      delete wsk;
      wsk = NULL;
    }
    else{
      prev->next = NULL;
      delete wsk;
    }
  }
}

int Lista::size(){
  if(first == NULL)
    return 0;
  else{
    pole *wsk = first;
    int i=1;
    while(wsk->next){
      wsk=wsk->next;
      i++;
    }
    return i;
  }
}

bool Lista::wykonaj_program(char* nazwa_pliku, int ilosc_danych){
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

void Lista::wyczysc_dane(int ile){
  for(int i=0;i<ile;i++)
    pop();
}
