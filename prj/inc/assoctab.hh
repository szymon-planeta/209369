#ifndef ASSOCTAB_HH
#define ASSOCTAB_HH

#include <cmath>
#include <string>
#include <sstream>
#include <typeinfo>
#include "ABData/list.hh"
#include "tools.hh"

#define TAB 1000
#define HASH 0.6180339887  //Donald Knuth hashing const

/*!
 * \file
 * \brief Definicja klasy AssocTab
 *
 */
template <class typeKey, class type>
class AssocTab{

  /*!
   * \brief Wskaznik na dynamicznie alokowana tablice z danymi
   */
  List<AssocData<typeKey, type> > *tab;

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
    tab = new List<AssocData<typeKey, type> > [TAB];
    counter = TAB;
  }
  /*!
   * \brief Konstruktor parametryczny
   *
   * Tworzy tablice, ktora zawiera zadana ilosc list. Ustawia counter zgodnie z ta wartoscia
   *
   * \param[in] howmany Z ilu list ma skladac sie tablica asocjacyjna
   */
  AssocTab(unsigned int howmany){
    tab = new List<AssocData<typeKey, type> > [howmany];
    counter = howmany;
  }

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych oraz przypisuje wskaznikowi
   * wartosc NULL.
   */
  ~AssocTab(){delete[] tab;}
 
/*!
   * \brief Metoda push
   *
   * Dodaje element o podanej wartosci na miejsce odczytywane przez klucz.
   *
   * \param[in] ikey Klucz, ktorym chcemy sie posluzyc
   * \param[in] toaddVal Wartosc, ktora chcemy dodac do tablicy.
   */
  void push(typeKey ikey, type toaddVal);

  /*!
   * \brief Procedura pop
   *
   * Usuwa z tablicy element odpowiadajacy podanemu kluczowi.
   *
   * \param[in] toremoveKey Klucz odpowiadajacy elementowi, ktory chcemy usunac
   */
  void pop(typeKey toremoveKey);

  /*!
   * \brief Metoda hash
   *
   * Dokonuje haszowania podanego klucza na wartosc liczbowa.
   *
   * \param[in] tohashKey Wartosc, ktora chcemy poddac haszowaniu.
   */
  int hash(typeKey tohashKey);

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
   * Zwraca element odpowiadajacy podanemu kluczowi.
   *
   * UWAGA! 
   * W przypadku proby odwolania sie do elementu o nieistniejacym kluczu, taki element zostanie
   * utworzony z przypadkowa wartoscia!
   *
   * \return Wartosc znajdujaca sie na miejscu o podanym kluczu
   */
  type& operator [] (const typeKey klucz);
};

template <class typeKey, class type>
void AssocTab<typeKey, type>::push(typeKey ikey, type toaddVal){
  AssocData<typeKey, type> toadd(ikey, toaddVal);
  tab[hash(ikey)].push(toadd);
}

template <class typeKey, class type>
int AssocTab<typeKey, type>::hash(typeKey tohashKey){
  string tohash;
  if(typeid(typeKey) == typeid(string))
    tohash = tohashKey; 
  else 
    tohash = tostring(tohashKey);
  double val=0; double add;
  for(unsigned int i=0; i<tohash.length(); i++){
    add = tohash[i]*(i+1);
    val+=add;
  }
  val*=HASH;
  val-=(int)val;
  return floor(counter*val);
}

template <class typeKey, class type>
type& AssocTab<typeKey, type>::operator [] (const typeKey klucz){
  for(unsigned int i=0; i<tab[hash(klucz)].size(); i++)
    if(tab[hash(klucz)][i].key == klucz)
      return tab[hash(klucz)][i].val;
  AssocData<typeKey, type> created(klucz);
  tab[hash(klucz)].push(created);
  return tab[hash(klucz)][0].val;
    
}

template <class typeKey, class type>
void AssocTab<typeKey, type>::pop(typeKey toremoveKey){
  for(unsigned int i=0; i<tab[hash(toremoveKey)].size(); i++)
    if(tab[hash(toremoveKey)][i].key == toremoveKey)
      tab[hash(toremoveKey)].pop(i);
}
#endif
