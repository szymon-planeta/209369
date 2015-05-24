#ifndef TREES_HH
#define TREES_HH

/*!
 * \file
 * \brief Definicja interfejsu dla drzew
 */

/*!
 * \brief Klasa abstrakcyjna zawierajaca metody wirtualne drzew
 */
template <class type>
class Trees{
public:
  virtual void insert(const type elem)=0;
  virtual bool remove(const type elem)=0;
  virtual bool search(const type elem)=0;
  virtual void clear()=0;
};

#endif
