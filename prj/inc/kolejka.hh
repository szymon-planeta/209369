#ifndef KOLEJKA_HH
#define KOLEJKA_HH

#include "program.hh"
#include "lista.hh"
/*!
 * \file
 * \brief Definicja klasy Kolejka
 */

class Kolejka: public Program{
  pole *head;
  pole *tail;

public:
  /*!
   *\ brief Konstruktor bezparametryczny
   *
   * Ustawia glowe (head) i ogon (tail) kolejki na NULL
   */
  Kolejka(){
    head = NULL;
    tail = NULL;
  }
  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na koniec kolejki.
   *
   * \param[in] x Wartosc, ktora chcemy dodac na koniec kolejki.
   */
  void push(int x);
  /*!
   * \brief Procedura pop
   *
   * Usuwa element z poczatku kolejki.
   */
  void pop();
  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze kolejki (liczbie jej elementow).
   *
   * \return Rozmiar kolejki (liczba jej elementow)
   */
  int size();

  /*!
   * \brief Metoda wykonaj_program
   *
   * Wykonuje zadany program - dodanie zadanej ilosci danych z pliku
   * do kolejki za pomoca metody push()
   *
   * \retval TRUE Poprawnie wykonano program
   * \retval FALSE Nie wczytano danych
   */
  bool wykonaj_program(char* nazwa_pliku,int ilosc_danych);

  /*!
   * \brief Metoda wyczysc_dane
   *
   * Usuwa zadana ilosc elementow kolejki za pomoca metody pop
   *
   * \param[in] ile Liczba elementow, ktore chcemy usunac.
   */
  void wyczysc_dane(int ile);
};

#endif
