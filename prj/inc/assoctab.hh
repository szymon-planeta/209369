#ifndef ASSOCTAB_HH
#define ASSOCTAB_HH

#include "iterable.hh"
#include "abdata.hh"

#define HASH 0.6180339887  //Donald Knuth hashing const
#define TAB 10000

/*!
 * \file
 * \brief Definicja klasy AssocTab
 */
template <class typeKey>
class AssocTab: public ABData<type>, public Iterable<type>{
  struct Data{
    typeKey key;
    typeVal val;
  };
  /*!
   * \brief Wskaznik na dynamicznie alokowana tablice z danymi
   */
  List<Data> *tab;

  /*!
   * \brief Aktualna liczba elementow w tablicy
   */
  int counter;

public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Tworzy tablice, ktora zawiera TAB list. Ustawia counter na TAB.
   */
  AssocTab(){
    tab = new List<Data> [TAB];
    counter = TAB;
  }

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych oraz przypisuje wskaznikowi
   * wartosc NULL.
   */
  ~Assoctab(){delete[] tab;}
 
/*!
   * \brief Metoda push
   *
   * Dodaje element o podanej wartosci na miejsce odczytywane przez klucz.
   *
   * \param[in] toaddKey Klucz, ktorym chcemy sie posluzyc
   * \param[in] toaddVal Wartosc, ktora chcemy dodac do tablicy.
   */
  void push(typeKey toaddKey, typeVal toaddVal);

  /*!
   * \brief Procedura pop
   *
   * Usuwa z tablicy element odpowiadajacy podanemu kluczowi.
   */
  void pop(typeKey toremoveKey);

  /*!
   * \brief Metoda hash
   *
   * Dokonuje haszowania podanego klucza na wartosc liczbowa.
   */
  int hash(typeK tohashKey);

  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze tablicy (liczbie jej elementow).
   *
   * \return Rozmiar tablicy (liczba jej elementow)
   */
  unsigned int size(){return counter;}

  /*!
   * \brief Przeciazenie operatora []
   *
   * Zwraca element o podanym indeksie (indeksowanie zaczyna się od 0)
   * W przypadku odwolania sie poza zakres, program przerywany jest z bledem 1.
   *
   * \return Wartosc znajdujaca sie na miejscu o podanym kluczu
   */
  typeVal& operator [] (const typeKey klucz);
};
#endif
