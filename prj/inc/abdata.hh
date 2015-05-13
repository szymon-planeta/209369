#ifndef ABDATA_HH
#define ABDATA_HH

/*!
 * \file
 * \brief Definicja klasy ABData
 *
 * Klasa ABData modeluje interfejs abstrakcyjnych typow danych
 * posiadajacych metody push(), pop() i size()
 */

template <class type>
class ABData{
  virtual void push(const type elem)=0;
  virtual void pop()=0;
  virtual unsigned int size()=0;
};

#endif
