//stos.hh
#ifndef STOS_HH
#define STOS_HH
#include "program.hh"
#include "lista.hh"

/*!
 * \file
 * \brief Definicja klasy Stos
 */


class Stos: public Program{
  pole *top;
public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia wierzcholek stosu na NULL
   */
  Stos(){
    top = NULL;
  }
  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na wierzcholek stosu.
   *
   * \param[in] x Wartosc, ktora chcemy dodac na wierzcholek stosu.
   */
  void push(int x);
  /*!
   * \brief Procedura pop
   *
   * Usuwa element znajdujacy sie na szczycie stosu (ostatnio dodany).
   */
  void pop();
 /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze stosu (liczbie jego elementow).
   *
   * \return Rozmiar stosu (liczba jego elementow)
   */
  int size();

 /*!
   * \brief Metoda wykonaj_program
   *
   * Wykonuje zadany program - dodanie zadanej ilosci danych z pliku
   * do stosu za pomoca metody push()
   *
   * \retval TRUE Poprawnie wykonano program
   * \retval FALSE Nie wczytano danych
   */
  bool wykonaj_program(char* nazwa_pliku,int ilosc_danych);

  /*!
   * \brief Metoda wyczysc_dane
   *
   * Usuwa zadana ilosc elementow stosu za pomoca metody pop
   *
   * \param[in] ile Liczba elementow, ktore chcemy usunac.
   */
  void wyczysc_dane(int ile);
};

#endif
