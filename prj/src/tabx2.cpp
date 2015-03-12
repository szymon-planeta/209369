#include "tabx2.hh"

using namespace std;
/*!\file
 * \brief Plik zawiera metody klasy Tabx2
 */
bool Tabx2::wykonaj_program(){
  if(rozmiar_tab==0){
    cerr<<"Brak danych wejsciowych!"<<endl;
    return false;
  }
  for(int i=0;i<rozmiar_tab;i++){
    tab[i]*=2;
  }
  return true;
}
