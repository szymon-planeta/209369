//kolejka.cpp
#include "kolejka.hh"
/*!\file
 * \brief Zawiera definicje metod klasy Kolejka
 */

void Kolejka::push(int x){
  pole *nowe = new pole;
  nowe->wartosc = x;
  if(head == NULL){
    head = nowe;
    tail = nowe;
  }
  else{
    tail->next = nowe;
    tail = nowe;
  }
}

void Kolejka::pop(){
  if(head == NULL)
    cerr<<"Kolejka jest pusta!"<<endl;
  else{
    pole *wsk = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    delete wsk;
  }
}

int Kolejka::size(){
  if(head == NULL)
    return 0;
  else{
    pole *wsk = head;
    int i=1;
    while(wsk->next){
      wsk=wsk->next;
      i++;
    }
    return i;
  }
}

bool Kolejka::wykonaj_program(char* nazwa_pliku, int ilosc_danych){
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

void Kolejka::wyczysc_dane(int ile){
  for(int i=0;i<ile;i++)
    pop();
}
