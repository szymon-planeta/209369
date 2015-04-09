//hashtab.hh
#ifndef HASHTAB_HH
#define HASHTAB_HH

#include "program.hh"

/*!
 * \file
 * \brief Definicja klasy Hashtab
 */

class Hashtab: public Program{
public:
  /*!
   * \brief Wskaznik na dynamicznie alokowana tablice z danymi
   */
  string *tab;

  
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
 Hashtab(){
    tab = new string [10000];
    rozmiar = 10000;
  }

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych oraz przypisuje wskaznikowi
   * wartosc NULL.
   */
  ~Hashtab(){delete[] tab; tab=NULL; rozmiar=0;}


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
  void push(string klucz, string wartosc);
 
  /*!
   * \brief Procedura pop
   *
   * Usuwa z tablicy wartosc odpowiadajaca danemu kluczowi.
   */
  void pop(string klucz);

  /*!
   * \brief Metoda hash
   *
   * Dokonuje haszowania podanego klucza na wartosc liczbowa.
   */
  int h(string klucz);

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
   * Wykonuje zadany program - dodanie zadanej ilosci danych z pliku
   * do listy za pomoca metody push()
   *
   * \retval TRUE Poprawnie wykonano program
   * \retval FALSE Nie wczytano danych
   */
  bool wykonaj_program(char* nazwa_pliku,int ilosc_danych){return true;}

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
   * Wyswietla element odpowiadajacy podanemu kluczowi
   */
  void wyswietl(string klucz);

 



};

#endif
