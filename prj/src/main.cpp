//main.cpp
#include <iostream>
#include "program.hh"
#include "tabx2.hh"
#include "benchmark.hh"

using namespace std;

int main(){
  Tabx2 a;
  Benchmark b;
  char* dane = (char*)"dane.dat";
  int ilosc_testow = 30;
  for(int ilosc_danych=50; ilosc_danych<1000000;ilosc_danych*=2){
    cout << b.testuj(a,dane,ilosc_danych,ilosc_testow) << endl;
  }
  return 0;
}
