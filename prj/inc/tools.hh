#ifndef TOOLS_HH
#define TOOLS_HH

/*!
 * \brief Plik zawiera definicje roznych przydatnych funkcji
 */

/*!
 * \brief Funkcja zamieia ze soba dwie wartosci podane w argumentach
 *
 * \param[in] val1 Pierwsza wartosc do zamiany
 * \param[in] val2 Druga wartosc do zamiany
 */
template <typename type>
void substitute(type& val1, type& val2){
  type tmp = val1;
  val1 = val2;
  val2 = tmp;
}

#endif
