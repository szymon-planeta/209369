//lista_tab.hh
#ifndef LISTA_TAB_HH
#define LISTA__TAB_HH

#include "program.hh"

/*!
 * \file
 * \brief Definicja klasy Lista_tab
 */

class Lista_tab: public Program{
  /*!
   * \brief Aktualny rozmiar tablicy
   */
  int rozmiar;
  /*!
   * \brief Iterator, zawierajacy informacje o liczbie elementow w tablicy
   */
  int iterator;
  /*!
   * \brief Wskaznik na dynamicznie alokowana tablice z danymi
   */
  int *tab;
public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia poczatek listy na NULL
   */
 Lista_tab(){
    tab = NULL;
    rozmiar = 0;
    iterator = 0;
  }

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych oraz przypisuje wskaznikowi
   * wartosc NULL.
   */
  ~Lista_tab(){delete[] tab; tab=NULL; rozmiar=0; iterator=0;}

  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na koniec listy.
   *
   * \param[in] x Wartosc, ktora chcemy dodac na koniec listy.
   */
  void push(int x);
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
  bool wykonaj_program(char* nazwa_pliku,int ilosc_danych);

  /*!
   * \brief Metoda wyczysc_dane
   *
   * Usuwa zadana ilosc elementow listy za pomoca metody pop
   *
   * \param[in] ile Liczba elementow, ktore chcemy usunac.
   */
  void wyczysc_dane(int ile);
};

#endif
