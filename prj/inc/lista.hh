//lista.hh
#ifndef LISTA_HH
#define LISTA_HH

#include "program.hh"

/*!
 * \file
 * \brief Definicja klasy Lista
 */

/*!
 * \brief Struktura pole
 *
 * Jest to struktura skladowa klasy Lista, zawierajaca
 * przechowywana wartosc oraz wskaznik na zmienna typu
 * pole.
 */
struct pole{
  int wartosc;
  pole *next;
  pole(){wartosc=0; next=NULL;}
};

class Lista: public Program{
  pole *first;
public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia poczatek listy na NULL
   */
 Lista(){
    first = NULL;
  }
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
