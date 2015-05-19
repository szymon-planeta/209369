#ifndef LISTARRAY_HH
#define LISTARRAY_HH

#include <iostream>
#include "iterable.hh"
#include "abdata.hh"

/*!
 * \file
 * \brief Definicja klasy ListArray
 */
template <class type>
class ListArray: public ABData<type>, public Iterable<type>{
  /*!
   * \brief Counter
   *
   * Przechowuje informacje o liczbie elementow znajdujacych sie na liscie
   */
  int counter;
  /*!
   * \brief Iterator
   *
   * Przechowuje informacje o aktualnej pozycji ostatniego elementu w tablicy
   */
  int iterator;
  /*!
   * \brief Wskaznik na dynamicznie alokowana tablice z danymi
   */
  type *tab;
public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia wskaznik na tablice na NULL, iterator na 0
   */
  ListArray(){
    tab = NULL;
    iterator = 0;
    counter = 0;
  }

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych 
   */
  ~ListArray(){delete[] tab;}

  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na koniec listy.
   *
   * \param[in] elem Wartosc, ktora chcemy dodac na koniec listy.
   */
  void push(const type elem);

  /*!
   * \brief Procedura pop
   *
   * Usuwa ostatni element listy.
   */
  void pop();

  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze listy (liczbie jej elementow).
   *
   * \return Rozmiar listy (liczba jej elementow)
   */
  unsigned int size();

  /*!
   * \brief Przeciazenie operatora []
   *
   * Zwraca element o podanym indeksie (indeksowanie zaczyna się od 0)
   * W przypadku odwolania sie poza zakres, program przerywany jest z bledem 1.
   *
   * \return Wartosc znajdujaca sie na miejscu o podanym indeksie
   */
  type& operator [] (const unsigned int index);
};

template <class type> 
void ListArray<type>::push(const type elem){
  if(counter==0){
    tab = new type [1];
    counter=1;
    iterator=0;
    tab[iterator]=elem;
  }
  else{
    if(iterator<counter-1){
      tab[++iterator]=elem;
    }
    else if(iterator>=counter-1){
      type *tmp = new type[2*counter];
      for(int i=0;i<=iterator;i++)
	tmp[i] = tab[i];
      delete [] tab;
      tab = tmp;
      tab[++iterator]=elem;
      counter*=2;
    }
  }
}

template <class type> 
void ListArray<type>::pop(){
 if(counter == 0){
    cerr<<"Lista jest pusta!"<<endl;
  }
  iterator--;
  if(iterator<0.25*(counter-1)){
    type *tmp = new type[iterator+1];
    for(int i=0;i<=iterator;i++){
      tmp[i]=tab[i];
    }  
    delete [] tab;
    tab = tmp;
    counter = iterator+1;
  }
}

template <class type> 
unsigned int ListArray<type>::size(){
  return iterator+1;
}

template <class type>
type& ListArray<type>::operator [] (const unsigned int index){
  if(index >= size()){ 
    std::cerr<<"Brak elementu o żądanym indeksie!"<<std::endl;
    exit(1);
  }
  else
    return tab[index];
}

#endif
