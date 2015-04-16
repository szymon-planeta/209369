//main.cpp
#include <iostream>
#include "program.hh"
#include "tabx2.hh"
#include "benchmark.hh"
#include "lista.hh"
#include "lista_tab.hh"
#include "assoctab.hh"

using namespace std;

int main(){
  
  Benchmark b;
  char* dane = (char*)"pary.dat";
  int ilosc_testow = 10;

  for(int ilosc_danych=1; ilosc_danych<=1000000;ilosc_danych*=10){
    Assoctab<string, string> asoc;
    asoc.wykonaj_program(dane,ilosc_danych);
    cout << b.testuj_strukture(asoc,dane,ilosc_danych,ilosc_testow) << endl;
  }

  return 0;
}
