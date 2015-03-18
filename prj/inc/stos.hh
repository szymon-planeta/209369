//stos.hh
#ifndef STOS_HH
#define STOS_HH
#include "program.hh"
#include "lista.hh"

/*!
 * \file
 * \brief Definicja klasy Stos
 */

/*!
 * \brief Struktura pole
 *
 * Jest to struktura skladowa klasy Lista, zawierajaca
 * przechowywana wartosc oraz wskaznik na zmienna typu
 * pole.
 */

class Stos: public Program{
public: //zmien zmien
  pole *top;
  Stos(){
     top = NULL;
   }
public:
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
};

#endif
