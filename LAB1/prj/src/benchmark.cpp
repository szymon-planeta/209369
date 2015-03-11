#include "benchmark.hh"
#include <iostream>
#include <sys/time.h>

void Benchmark::rozpocznij_pomiar(){
  gettimeofday(&t1, NULL);
}

void Benchmark::zakoncz_pomiar(){
  gettimeofday(&t2, NULL);
  czas_pomiaru = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  czas_pomiaru += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
}

double Benchmark::testuj(Program &program, char* dane, int ilosc_danych, int ilosc_testow){
  //tab_pomiarow = new double [ilosc_testow];
  double suma=0;
  double srednia=0;
  for(int i=0;i<ilosc_testow;i++){
    rozpocznij_pomiar();
    program.wczytaj_dane(dane);
    program.wykonaj_program();
    zakoncz_pomiar();
    //tab_pomiarow[i] = czas_pomiaru;
    suma+=czas_pomiaru;
  }
  srednia=suma/(ilosc_testow);
  //delete [] tab_pomiarow;
  return srednia;
}
