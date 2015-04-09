#include "hashtab.hh"

using namespace std;
/*!\file
 * \brief Plik zawiera metody klasy Hashtab
 */

void Hashtab::push(string klucz, string wartosc){
  tab[h(klucz)] = wartosc;					 
}

void Hashtab::pop(string klucz){
  tab[h(klucz)] = "0";
}

void Hashtab::wyswietl(string klucz){
  cout << tab[h(klucz)];
}

int Hashtab::size(){
  return rozmiar;
}


int Hashtab::h(string klucz){
  int val=0; int add;
  for(unsigned int i=0; i<klucz.length(); i++){
    add = klucz[i]*(i+1);
    val+=add;
  }
  return val%rozmiar;
}

