#include "benchmark.hh"

/*!\file
 * \brief Plik zawiera metody klasy Benchmark
 */

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
  
  //if(program.wczytaj_dane(dane,ilosc_danych)==false){
  //     cerr<<"Niewystarczajaca ilosc danych!"<<endl;
  //    return 0;
  // }
  //char* dane_wy = (char*)"dane_wy.dat"; //do zapisu do pliku
  //program.wykonaj_program();
  //rozpocznij_pomiar();
  //program.test();
  //program.zapisz_dane(dane_wy);//zapisywanie wynikow do pliku
  //zakoncz_pomiar();
  //suma+=czas_pomiaru;
  for(int i=1;i<ilosc_testow;i++){
    //program.wczytaj_dane(dane,ilosc_danych); //zawsze dane od poczatku
    rozpocznij_pomiar();
    //program.wykonaj_program();
    program.test();
    zakoncz_pomiar();
    suma+=czas_pomiaru;
  }
  srednia=suma/(ilosc_testow);
  wyniki<<endl<<ilosc_danych<<","<<srednia;
  wyniki.close();
  return srednia;
}

double Benchmark::testuj_strukture(Program &program,char* dane, int ilosc_danych, int ilosc_testow){
  double suma=0;
  double srednia=0;
  ofstream wyniki;
  wyniki.open("wyniki.csv",ios::app);
  for(int i=1;i<ilosc_testow;i++){
    rozpocznij_pomiar();
    program.test();
    zakoncz_pomiar();
    suma+=czas_pomiaru;
  }
  srednia=suma/(ilosc_testow);
  wyniki<<endl<<ilosc_danych<<","<<srednia;
  wyniki.close();
  return srednia;
 
}
