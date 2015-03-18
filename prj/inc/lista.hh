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
  public: //zmien zmien
  pole *first;
  Lista(){
    first = NULL;
  }
public:
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
};

#endif
