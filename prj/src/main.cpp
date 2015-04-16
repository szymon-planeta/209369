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
  Lista_tab a;
  Benchmark b;
  char* dane = (char*)"dane.dat";
  int ilosc_testow = 10;
  
    a.wykonaj_program(dane, 10);
    for(int i=0; i<=a.iterator; i++)
    cout<< a.tab[i]<<endl;
    a.mergesort(0,a.iterator);
    cout<<endl<<endl;
    for(int i=0; i<=a.iterator; i++)
    cout<< a.tab[i]<<endl;
  
  /*
  for(int ilosc_danych=1; ilosc_danych<=10000000;ilosc_danych*=10){
    cout << b.testuj_strukture(a,dane,ilosc_danych,ilosc_testow) << endl;
  }
  */  
  return 0;
}
