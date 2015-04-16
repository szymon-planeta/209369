#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

long long int ilosc;
int dlugosc;
ofstream plik;

void gen_random(char *s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

int main(){
  char napis[11];
  cout<<"GENERATOR LICZB LOSOWYCH"<<endl;
  cout<<"Program generuje zadana przez uzytkownika ilosc danych z zadanego przedzialu"<<endl<<" i zapisuje je do pliku dane.dat"<<endl<<endl;
  cout<<"Podaj ilosc liczb, jakie chcesz wygenerowac: ";
  cin>>ilosc;
  cout<<"Podaj dlugosc napisow: ";
  cin>>dlugosc;
  
  plik.open("pary.dat");
  
  for(long long int i=1;i<=ilosc;i++){
    gen_random(napis, dlugosc);
    plik<<napis;
    gen_random(napis, dlugosc);
    plik<<" "<<napis<<endl;
  }
  plik.close();
  
}
