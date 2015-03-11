//program.cpp
#include "program.hh"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool Program::wczytaj_dane(char* nazwa_pliku){
  if(plik_we.good()==true)
    plik_we.close();
  plik_we.open(nazwa_pliku);
  if(plik_we.good()==false){
    cerr<<"Blad odczytu pliku!";
    return false;
  }
  plik_we >> rozmiar_tab;
  tab=new int [rozmiar_tab];
  int i=0;
  while(plik_we >> tab[i]){
    i++;
  }
  plik_we.close();
  return true;
}

bool Program::wczytaj_dane(char* nazwa_pliku, int ile_danych){
  if(plik_we.good()==true)
    plik_we.close();
  plik_we.open(nazwa_pliku);
  if(plik_we.good()==false){
    cerr<<"Blad odczytu pliku!"<<endl;
    return false;
  }
  plik_we >> rozmiar_tab;
  if(ile_danych>rozmiar_tab){
    plik_we.close();
    return false;
  }
  rozmiar_tab=ile_danych;
  tab=new int [ile_danych];
  for(int i=0;i<ile_danych;i++)
    plik_we>>tab[i];
  plik_we.close();
  return true;
}

bool Program::zapisz_dane(char* nazwa_pliku){
  if(plik_wy.good()==true)
    plik_wy.close();
  plik_wy.open(nazwa_pliku);
  if(plik_wy.good()==false){
    cerr<<"Blad odczytu pliku!";
    return false;
  }
  plik_wy << rozmiar_tab << endl;
  for(int i=0;i<rozmiar_tab;i++)
    plik_wy << tab[i] << endl;
  plik_wy.close();
  return true;
}

void Program::wyswietl_dane(){
  for(int i=0;i<rozmiar_tab;i++)
    cout<<tab[i]<<endl;
}

bool Program::wykonaj_program(){
  cerr<<"Nie wybrano programu do wykonania!"<<endl;
  return false;
}
