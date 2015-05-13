#ifndef NODE_HH
#define NODE_HH

 /*! \file
   * \brief Struktura node
   *
   * Jest to struktura skladowa klasy List, zawierajaca
   * przechowywana wartosc oraz wskaznik na zmienna typu
   * node.
   */
template <typename type>
struct node{
  /*!
   * \brief Przechowywane dane
   */
  type val;
  /*! 
   * \brief Wskaznik na nastepny node
   */
  node *next;
  /*!
   * \brief Konstruktor bezparametryczny
   */
  node(){
    next=NULL;
  }
  /*!
   * \brief Konstruktor parametryczny
   */
  node(type elem){
    val=elem; 
    next=NULL;
  }
};

#endif
