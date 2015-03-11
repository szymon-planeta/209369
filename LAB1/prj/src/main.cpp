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
  cout << b.testuj(a,dane,10000,3) << endl;
 
  return 0;
}
