//main.cpp
#include <iostream>
#include "program.hh"
#include "tabx2.hh"
#include "benchmark.hh"
#include "stos.hh"
#include "kolejka.hh"
#include "lista.hh"
#include "lista_tab.hh"
#include "hashtab.hh"

using namespace std;

int main(){
  Hashtab haszek;
 
  haszek.push("rudolf","koban");
  haszek.push("flodur","planeta");

  haszek.wyswietl("rudolf");
  cout << endl;
  haszek.wyswietl("flodur");
  cout << endl;
  
  return 0;
}
