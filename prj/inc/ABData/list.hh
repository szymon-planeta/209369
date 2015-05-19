#ifndef LIST_HH
#define LIST_HH

#include <iostream>
#include <cstdlib>
#include "node.hh"
#include "iterable.hh"
#include "abdata.hh"
/*!
 * \file
 * \brief Definicja klasy List
 */

template <class type>
class List: public ABData<type>, public Iterable<type>{
  /*!
   * \brief Wskaznik head
   *
   * Wskaznik na pierwszy element listy
   */
  node<type> *head;
  /*!
   * \brief Iterator
   *
   * Przechowuje informacje o liczbie elementow znajdujacych sie na liscie
   */
  int iterator;
public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia poczatek listy na NULL
   */
  List(){
    head = NULL;
    iterator = 0;
  }

  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na poczatek listy.
   *
   * \param[in] elem Wartosc, ktora chcemy dodac na poczatek listy.
   */
  void push(const type elem);

  /*!
   * \brief Procedura pop
   *
   * Usuwa pierwszy element listy.
   */
  void pop();

/*!
   * \brief Procedura pop
   *
   * Usuwa element o wybranym indeksie z listy.
   */
  void pop(unsigned int index);

  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze listy (liczbie jej elementow).
   *
   * \return Rozmiar listy (liczba jej elementow)
   */
  unsigned int size();

  /*!
   * \brief Przeciazenie operatora []
   *
   * Zwraca element o podanym indeksie (indeksowanie zaczyna się od 0)
   * W przypadku odwolania sie poza zakres, program przerywany jest z bledem 1.
   *
   * \return Wartosc znajdujaca sie na miejscu o podanym indeksie
   */
  type& operator [] (const unsigned int index);
};
/***************************************************/
/*                                                 */
/*                END OF CLASS                     */
/*                                                 */
/***************************************************/
template <class type> 
void List<type>::push(const type elem){
  node<type> *toadd = new node<type>;
  toadd->val = elem;
  node<type> *ptr = head;
  head = toadd;
  toadd->next = ptr;
  iterator++;
}

template <class type> 
void List<type>::pop(){
  if(!head)
    std::cerr<<"Lista jest pusta!"<<std::endl;
  else{
    node<type> *ptr = head;
    head = head->next;
    delete ptr;
    iterator--;
  }
}

template <class type> 
void List<type>::pop(unsigned int index){
  if(!head)
    std::cerr<<"Lista jest pusta!"<<std::endl;
  else{
    node<type> *ptr = head;
    if(index==0){
      head=head->next;
      delete ptr;
      iterator--;
    }
    else{
      ptr=ptr->next;
      node<type> *prev = head;
      unsigned int i=1;
	for(; i<index && ptr->next; i++){
	  ptr = ptr->next;
	  prev = prev->next;
	}
      if(i==index){
	prev->next=ptr->next;
	delete ptr;
	iterator--;
      }
      else
	std::cerr<<"Brak elementu o podanym indeksie!"<<std::endl;
    }
  }
}

template <class type> 
unsigned int List<type>::size(){
  return iterator;
}

template <class type>
type& List<type>::operator [] (const unsigned int index){
  if(index >= size()){ 
    std::cerr<<"Brak elementu o żądanym indeksie!"<<std::endl;
    exit(1);
  }
  else{
    node<type> *ptr = head;
    for(unsigned int i=1; i<=index; i++)
      ptr=ptr->next;
    return ptr->val;
    }
}

#endif