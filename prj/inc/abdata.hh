#ifndef ABDATA_HH
#define ABDATA_HH

/*!
 * \file
 * \brief Definicja wirtualnej klasy ABData
 *
 * Klasa ABData modeluje interfejs abstrakcyjnych typow danych
 * posiadajacych metody push(), pop() i size()
 */

/*!
 * \brief Modeluje klase wirtualna ABData, ktora jest interfejsem.
 */
template <class type>
class ABData{
public:
  virtual void push(const type elem)=0;
  virtual void pop()=0;
  virtual unsigned int size()=0;
};

#endif
