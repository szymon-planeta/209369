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
  for(int i=0;i<1000;i++){
    a.push(10000000);
  }
  cout<<"Rozmiar: "<<a.size()<<endl;
  a.pop(); a.pop(); a.pop();
  cout<<"Rozmiar: "<<a.size()<<endl;
  
  //Benchmark b;
  //char* dane = (char*)"dane.dat";
  //A.wczytaj_dane(dane);



  //int ilosc_testow = 30;
  // for(int ilosc_danych=50; ilosc_danych<1000000;ilosc_danych*=2){
  // cout << b.testuj(a,dane,ilosc_danych,ilosc_testow) << endl;
  //}
  return 0;
}
