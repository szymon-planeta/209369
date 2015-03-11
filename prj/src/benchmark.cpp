#include "benchmark.hh"
#include <iostream>
#include <sys/time.h>
#include <fstream>

void Benchmark::rozpocznij_pomiar(){
  gettimeofday(&t1, NULL);
}

void Benchmark::zakoncz_pomiar(){
  gettimeofday(&t2, NULL);
  czas_pomiaru = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  czas_pomiaru += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
}

double Benchmark::testuj(Program &program, char* dane, int ilosc_danych, int ilosc_testow){
  double suma=0;
  double srednia=0;
  ofstream wyniki;
  wyniki.open("wyniki.csv",ios::app);
  rozpocznij_pomiar();
  if(program.wczytaj_dane(dane,ilosc_danych)==false){
      cerr<<"Niewystarczajaca ilosc danych!"<<endl;
      return 0;
    }
  char* dane_wy = (char*)"dane_wy.dat";
  program.wczytaj_dane(dane,ilosc_danych);
  program.wykonaj_program();
  program.zapisz_dane(dane_wy);
  zakoncz_pomiar();
  suma+=czas_pomiaru;
  for(int i=1;i<ilosc_testow;i++){
    rozpocznij_pomiar();
    program.wczytaj_dane(dane,ilosc_danych);
    program.wykonaj_program();
    zakoncz_pomiar();
    suma+=czas_pomiaru;
  }
  srednia=suma/(ilosc_testow);
  wyniki<<endl<<ilosc_danych<<","<<srednia;
  wyniki.close();
  return srednia;
}
