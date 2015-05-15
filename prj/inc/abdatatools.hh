#ifndef ABDATATOOLS_HH
#define ABDATATOOLS_HH

#include "abdata.hh"
#include <iostream>

/*
 *!\file 
 * \brief Plik zawiera definicje funkcji operujacych na obiektach o klasie nadrzednej 
 * ABData.
 */

/*!
 * \brief Wypelnia zadana strukture zadana iloscia danych wczytywana z zadanego pliku.
 *
 * \param[in] *item Wskaznik do obiektu typu dziedziczacego z ABData, ktory chcemy wypelnic
 * \param[in] amount Ilosc danych, jakie chcemy wczytac do obiektu
 * \param[in] fileName Nazwa pliku, z ktorego wczytujemy dane
 */
template <typename type>
bool fillFromFile(ABData<type> *item, const int amount, const char* fileName){
  ifstream inputFile;
  inputFile.open(fileName);
  if(inputFile.good()==false){
    std::cerr<<"Blad odczytu pliku!"<<std::endl;
    return false;
  }
  type tmp;
  for(int i=0; i<amount; i++){
    inputFile >> tmp;
    item->push(tmp);
    }
  inputFile.close();
  return true;
}

/*!
 * \brief Usuwa wszystkie dane znajdujace sie w strukturze.
 *
 * \param[in] *item Wskaznik do obiektu typu dziedziczacego z ABData, ktory chcemy wyczyscic
 */
template <typename type>
void clear(ABData<type> *item){
  while(item->size() > 0)
    item->pop();
}

#endif
