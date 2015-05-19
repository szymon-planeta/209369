#ifndef ITERABLE_HH
#define ITERABLE_HH 

/*!
 * \file 
 * \brief Plik zawiera definicje klasy Iterable
 */

/*!
 * \brief Modeluje klase wirtualna Iterable.
 *
 * Jest to interfejs dla klas z przeciazonym operatorem indeksowania [].
 */
template <class type>
class Iterable{
public:
  virtual type& operator [](const unsigned int index)=0;
};

/*!
 * \brief Funkcja display
 *
 * Pozwala na wyswietlenie zadanej ilosci danych obiektu typu iterable
 *
 * \param[in] todisplay Referencja do obiektu typu Iterable
 * \param[in] howmany Ilosc danych do wyswietlenia
 */
template <class type>
void display(Iterable<type> &todisplay, unsigned int howmany){
  for(unsigned int i=0; i<howmany; i++)
    std::cout<<todisplay[i]<<std::endl;
}

#endif
