#ifndef STACK_HH
#define STACK_HH 

#include <iostream>
#include <cstdlib>
#include "node.hh"
#include "iterable.hh"
#include "abdata.hh"


template <class type>
class Stack: public ABData<type>, public Iterable<type>{

  /*!
   * \brief Wskaznik head
   *
   * Wskaznik na pierwszy element stosu
   */
  node<type> *head;
  /*!
   * \brief Iterator
   *
   * Przechowuje informacje o liczbie elementow znajdujacych sie na stosie
   */
  int iterator;

public:
 /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia poczatek listy na NULL
   */
  Stack(){
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
   * Usuwa pierwszy element stosu.
   */
  void pop();

  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze stosu (liczbie jego elementow).
   *
   * \return Rozmiar stosu (liczba jego elementow)
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


void display(){
  node<type> *ptr = head;
  while(ptr){
    std::cout<<ptr->val<<std::endl;
    ptr=ptr->next;
  }
}
};

template <class type> 
void Stack<type>::push(const type elem){
  node<type> *toadd = new node<type>;
  toadd->val = elem;
  node<type> *ptr = head;
  head = toadd;
  toadd->next = ptr;
  iterator++;
}

template <class type> 
void Stack<type>::pop(){
  if(!head)
    std::cerr<<"Stos jest pusty!"<<std::endl;
  else{
    node<type> *ptr = head;
    head = head->next;
    delete ptr;
    iterator--;
  }
}

template <class type> 
unsigned int Stack<type>::size(){
  return iterator;
}

template <class type>
type& Stack<type>::operator [] (const unsigned int index){
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
