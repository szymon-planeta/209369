#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

long long int ilosc;
int dol,gora;
ofstream plik;

int main(){
  cout<<"GENERATOR LICZB LOSOWYCH"<<endl;
  cout<<"Program generuje zadana przez uzytkownika ilosc danych z zadanego przedzialu"<<endl<<" i zapisuje je do pliku dane.dat"<<endl<<endl;
  cout<<"Podaj ilosc liczb, jakie chcesz wygenerowac: ";
  cin>>ilosc;
  cout<<"Podaj dolna granice przedzialu: ";
  cin>>dol;
  cout<<"Podaj gorna granice przedzialu: ";
  cin>>gora;
  plik.open("dane.dat");
  plik<<ilosc<<endl;
  for(long long int i=1;i<=ilosc;i++){
    plik<<rand()%(gora-dol+1)+dol<<endl;
  }
  plik.close();
  
}