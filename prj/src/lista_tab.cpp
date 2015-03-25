//lista_tab.cpp
#include "lista_tab.hh"

/*!\file 
 * \brief Zawiera definicje metod klasy Lista
 */
// ZWIEKSZA SIE O 1
void Lista_tab::push(int x){
  if(rozmiar==0){
    tab = new int [1];
    rozmiar=1;
    iterator=0;
    tab[iterator]=x;
  }
  else{
    if(iterator<rozmiar-1){
      tab[++iterator]=x;
    }
    else if(iterator>=rozmiar-1){
      int *tmp = new int[rozmiar+1];
      for(int i=0;i<=iterator;i++)
	tmp[i] = tab[i];
      delete [] tab;
      tab = tmp;
      tab[++iterator]=x;
      rozmiar++;
    }
  }
}
//TABLICA POWIEKSZANA DWUKROTNIE
/*
   void Lista_tab::push(int x){
   if(rozmiar==0){
   tab = new int [1];
    rozmiar=1;
    iterator=0;
    tab[iterator]=x;
  }
  else{
    if(iterator<rozmiar-1){
      tab[++iterator]=x;
    }
    else if(iterator>=rozmiar-1){
      int *tmp = new int[2*rozmiar];
      for(int i=0;i<=iterator;i++)
	tmp[i] = tab[i];
      delete [] tab;
      tab = tmp;
      tab[++iterator]=x;
      rozmiar*=2;
    }
  }
  }*/


void Lista_tab::pop(){
  if(rozmiar == 0){
    cerr<<"Lista jest pusta!"<<endl;
  }
  iterator--;
  if(iterator<0.25*(rozmiar-1)){
    int *tmp = new int[iterator+1];
    for(int i=0;i<=iterator;i++){
      tmp[i]=tab[i];
    }  
    delete [] tab;
    tab = tmp;
    rozmiar = iterator+1;
  }
}


int Lista_tab::size(){
  return rozmiar;
}

bool Lista_tab::wykonaj_program(char* nazwa_pliku, int ilosc_danych){
  int tmp;
  plik_we.open(nazwa_pliku);
  if(plik_we.good()==false){
    cerr<<"Blad odczytu pliku!"<<endl;
    return false;
  }
  plik_we >> rozmiar_tab;  //pozbyc sie pierwszej liczby z pliku z danymi
  for(int i=0;i<ilosc_danych;i++){
    plik_we >> tmp;
    push(tmp);
  }
  plik_we.close();
  return true;
}

void Lista_tab::wyczysc_dane(int ile){
  delete [] tab;
  rozmiar = 0;
  iterator = 0;
  tab = NULL;
}

