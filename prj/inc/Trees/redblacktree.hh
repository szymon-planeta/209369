#ifndef REDBLACKTREE_HH
#define REBBLACKTREE_HH

#include <iostream>
#include "trees.hh"

template <typename type>
struct rbtreenode{
  /*!
   * \brief Przechowywana wartosc
   */
  type val;
  /*!
   * \brief Wskaznik na lewy wezel
   */
  rbtreenode *left;
  /*!
   * \brief Wskaznik na prawy wezel
   */
  rbtreenode *right;
  /*!
   * \brief Wskaznik na rodzica
   */
  rbtreenode *parent;
  /*!
   * \brief Kolor wezla
   *
   * true - wezel ma kolor czerwony
   * false - wezel ma kolor czarny
   */
  bool Red;
  /*!
   * \brief Konstruktor parametryczny
   *
   * Tworzy wezel o podanej wartosci ze wskaznikami ustawionymi na NULL
   *
   * \param[in] elem Zadana wartosc
   */
  rbtreenode(type elem){val=elem; left=NULL; right=NULL; Red=false;}
};

/*!
 * \brief Klasa RedBlackTree - drzewo czerwono-czarne
 */
template <typename type>
class RedBlackTree: public Trees<type>{
private:
  /*!
   * \brief Root - korzen drzewa - wskaznik na pierwszy element drzewa
   */
  rbtreenode<type> *root;
  /*!
   * \brief Sentinel - straznik
   */
  rbtreenode<type> *sentinel;

  void insert(const type elem, rbtreenode<type> *leaf);
  void print(rbtreenode<type> *root);
public: 
  RedBlackTree(){
    root = NULL;
    sentinel = new rbtreenode<type>(type());
  }

  void insert(const type elem);
  bool remove(const type elem){return true;}
  bool search(const type elem){return true;}
  void print();

};
////////////////////////////////////////
////////////////////////////////////////

template <class type>
void RedBlackTree<type>::insert(const type elem){
  if(root!=NULL)
    insert(elem, root);
  else
    root = new rbtreenode<type>(elem);
}

template <class type>
void RedBlackTree<type>::insert(const type elem, rbtreenode<type> *leaf){
  if(elem < leaf->val){
    if(leaf->left!=NULL)
      insert(elem, leaf->left);
    else
      leaf->left = new rbtreenode<type>(elem);
  }
  else if(elem >= leaf->val){
    if(leaf->right!=NULL)
      insert(elem, leaf->right);
    else
      leaf->right = new rbtreenode<type>(elem);
  }
}

template <class type>
void RedBlackTree<type>::print(){
  if(root != NULL){
    std::cout << root->val << " ";
    print(root->left);
    print(root->right);
  }
}

template <class type>
void RedBlackTree<type>::print(rbtreenode<type> *root){
  if(root != NULL){
    std::cout << root-> val << " ";
    print(root->left);
    print(root->right);
  }
}

#endif
