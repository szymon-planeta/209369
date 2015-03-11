//mnozenie_tablicy.hh

#ifndef TABX2_HH
#define TABX2_HH

/*!
 * \file
 * \brief Definicja klasy Tabx2
 *
 * Klasa Tabx2 jest klasa pochodna od klasy Program.
 * Definiuje metode podawajajaca kazda liczbe znajdujaca sie w tablicy danych
 * wskazywanej przez zmienna tab klasy Program.
 */

#include <iostream>
#include "program.hh"

class Tabx2: public Program{

public:
  /*!
   * \brief Metoda wirtualna wykonaj_program.
   *
   * Dokonuje przemnozenia przez 2 wszystkich danych znajdujacych sie 
   * w tablicy wskazywanej przez tab.
   *
   * \retval TRUE Poprawnie dokonano mnozenia wszystkich liczb
   * \retval FALSE Rozmiar tablicy danych wynosi 0
   */
  virtual bool wykonaj_program();
};

#endif
