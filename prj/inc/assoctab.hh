//assoctab.hh
#ifndef ASSOCTAB_HH
#define ASSOCTAB_HH

//Donald Knuth hashing const
#define HASH 0.6180339887
#define TAB 10000

#include "program.hh"
#include <cmath>

/*!
 * \file
 * \brief Definicja klasy Assoctab
 */

template <class typeK, class typeV>
class Assoctab: public Program{
public:
  /*!
   * \brief Wskaznik na dynamicznie alokowana tablice z danymi
   */
  Lista<typeK, typeV> *tab;

  
  /*!
   * \brief Aktualny rozmiar tablicy
   */
  int rozmiar;

public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia poczatek listy na NULL
   */
    Assoctab(){
    tab = new Lista<typeK, typeV> [TAB];
    rozmiar = TAB;
  }

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych oraz przypisuje wskaznikowi
   * wartosc NULL.
   */
  ~Assoctab(){delete[] tab; tab=NULL; rozmiar=0;}


/*!
   * \brief Procedura push
   *
   * Dodaje element o podanej wartosci na miejsce odczytywane przez klucz.
   * Do wyboru 2 metody push - po osiagnieciu maksymalnego rozmiaru
   * tablicy, jedna z nich zwieksza rozmiar tablicy o 1, a druga
   * podwaja aktualny rozmiar tablicy. Wyboru metody nalezy dokonac
   * poprzed odkomentowanie odpowiedniej metody w pliku .cpp.
   *
   * \param[in] x String, ktory chcemy dodac na koniec listy.
   */
  void push(typeK klucz, typeV wartosc);
 
  /*!
   * \brief Procedura pop
   *
   * Usuwa z tablicy wartosc odpowiadajaca danemu kluczowi.
   */
  void pop(typeK klucz);

  /*!
   * \brief Metoda hash
   *
   * Dokonuje haszowania podanego klucza na wartosc liczbowa.
   */
  int h(typeK klucz);

  //int h(string klucz);

  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze tablicy (liczbie jej elementow).
   *
   * \return Rozmiar tablicy (liczba jej elementow)
   */
  int size();

    /*!
   * \brief Metoda wykonaj_program
   *
   * Wczytuje zadana ilosc danych do tablicy asocjacyjnej
   *
   * \retval TRUE Poprawnie wykonano program
   * \retval FALSE Nie wczytano danych
   */
  bool wykonaj_program(char* nazwa_pliku,int ilosc_danych);

  /*!
   * \brief Metoda test()
   *
   * Przeprowadza test - odwoluje sie do pojedynczego klucza
   */
  void test(){
    //typeV a = tab[h("fa37")].daj("fa37");
    wyswietl("fa37");
  };

  /*!
   * \brief Metoda wyczysc_dane
   *
   * Usuwa zadana ilosc elementow listy za pomoca metody pop
   *
   * \param[in] ile Liczba elementow, ktore chcemy usunac.
   */
  void wyczysc_dane(int ile){}


  /*!
   * \brief Metoda wyswietl
   *
   * Wyswietla wszystkie elementy, ktorych klucze po haszowaniu maja te sama wartosc
   */
  void wyswietl_liste(typeK klucz);
  /*!
   * \brief Metoda wyswietl
   *
   * Wyswietla elementy dokladnie odpowiadajace podanemu kluczowi
   *
   * \param[in] Klucz
   */
  void wyswietl(typeK klucz);
  
  /*
   * \brief Przeciazenie operatora []
   */
  const typeV& operator[](typeK klucz)const;

  /*
   * \brief Przeciazenie operatora []
   */
  typeV& operator[](typeK klucz);


 
};

template <class typeK, class typeV> void Assoctab<typeK, typeV>::push(typeK klucz, typeV wartosc){
  tab[h(klucz)].push_front(klucz, wartosc);	 				 
}

template <class typeK, class typeV> void Assoctab<typeK, typeV>::pop(typeK klucz){
  tab[h(klucz)].pop(klucz);
}

template<class typeK, class typeV> int Assoctab<typeK, typeV>::h(typeK klucz){
  double val=0; double add;
  for(unsigned int i=0; i<klucz.length(); i++){
    add = klucz[i]*(i+1);
    val+=add;
  }
  val*=HASH;
  val-=(int)val;
  return floor(rozmiar*val);
}

template <class typeK, class typeV> int Assoctab<typeK, typeV>::size(){
  return rozmiar;
}

template <class typeK, class typeV> bool Assoctab<typeK, typeV>::wykonaj_program(char* nazwa_pliku,int ilosc_danych){
  typeK key;
  typeV val;
  plik_we.open(nazwa_pliku);
  if(plik_we.good()==false){
    cerr<<"Blad odczytu pliku!"<<endl;
    return false;
  }
  for(int i=0;i<ilosc_danych;i++){
    plik_we >> key;
    plik_we >> val;
    push(key,val);
  }
  plik_we.close();
  return true;
}

template <class typeK, class typeV> void Assoctab<typeK, typeV>::wyswietl_liste(typeK klucz){
  tab[h(klucz)].wyswietl();				 
}

template <class typeK, class typeV> void Assoctab<typeK, typeV>::wyswietl(typeK klucz){
  tab[h(klucz)].wyswietl(klucz);				 
}

template <class typeK, class typeV> const typeV& Assoctab<typeK,typeV>::operator[](typeK klucz)const{
  return tab[h(klucz)].daj(klucz);
}

template <class typeK, class typeV> typeV& Assoctab<typeK,typeV>::operator[](typeK klucz){
  return tab[h(klucz)].daj(klucz);
}
#endif
