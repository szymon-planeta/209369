//main.cpp
#include <iostream>
#include "program.hh"
#include "tabx2.hh"
#include "benchmark.hh"
#include "stos.hh"
#include "kolejka.hh"
#include "lista.hh"

using namespace std;

int main(){
  Lista a;
  Benchmark b;
  char* dane = (char*)"dane.dat";
  int ilosc_testow = 10;
  for(int ilosc_danych=10; ilosc_danych<=100000000;ilosc_danych*=2){
    cout << b.testuj_strukture(a,dane,ilosc_danych,ilosc_testow) << endl;
  }
  return 0;
}
