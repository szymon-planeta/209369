#ifndef BINARYTREE_HH
#define BINARYTREE_HH 

#include <iostream>
#include <cstdlib>
#include "../ABData/list.hh"
#include "trees.hh"

/*!
 * \file
 * \brief Definicja klasy drzewa binarnego
 */

/*!
 * \brief Wezel drzewa
 */
template <typename type>
struct treenode{
  /*!
   * \brief Przechowywana wartosc
   */
  type val;
  /*!
   * \brief Wskaznik na lewy wezel
   */
  treenode *left;
  /*!
   * \brief Wskaznik na prawy
   */
  treenode *right;

  /*!
   * \brief Konstruktor parametryczny
   *
   * Tworzy wezel o podanej wartosci ze wskaznikami ustawionymi na NULL
   *
   * \param[in] elem Zadana wartosc
   */
  treenode(type elem){
    val = elem;
    left = NULL;
    right = NULL;
  }
};

/*!
 * \brief Klasa BinaryTree - drzewo binarne
 */
template <class type>
class BinaryTree: public Trees<type>{
private:
  /*!
   * \brief Root - korzen drzewa - wskaznik na pierwszy element drzewa
   */
  treenode<type> *root;
  /*!
   * \brief Metoda prywatna insert
   *
   * Metoda pomocniczna do wywolan rekurencyjnych
   */
  void insert(const type elem, treenode<type> *leaf);
  /*!
   * \brief Metoda prywatna print
   *
   * Metoda pomocniczna do wywolan rekurencyjnych
   */
  void print(treenode<type> *root);

  /*!
   * \brief Metoda prywatna insert
   *
   * Metoda pomocniczna do wywolan rekurencyjnych
   */
  treenode<type> * remove(treenode<type> * node, const type elem);

  /*!
   * \brief Metoda findMin
   *
   * Metoda pomocniczna znajdujaca najmniejsza wartosc w podanym poddrzewie
   *
   */
  treenode<type> * findMin(treenode<type> *node);
public:
  /*!
   * \brief Konstruktor bezparametryczny
   */
  BinaryTree(){
    root = NULL;
  }
  /*!
   * \brief Metoda insert
   *
   * Sluzy do wstawienia zadanego elementu w odpowniednie miejsce drzewa
   *
   * \param[in] elem Wartosc do wstawienia
   */
  void insert(const type elem);
  /*!
   * \brief Metoda remove
   *
   * Sluzy do usuniecia z drzewa elementu o zadanej wartosci
   *
   * \param[in] elem Wartosc elementu do usuniecia
   * 
   * \retval TRUE Usunieto elemeny]t
   * \retval FALSE Brak elemetu o zadanej wartosci
   */
  bool remove(const type elem);
  /*!
   * \brief Metoda search
   *
   * Sluzy do sprawdzenia, czy w drzewie znajduje sie element o zadanej wartosci
   *
   * \param[in] elem Wartosc elementu do znalezienia
   *
   * \retval TRUE Element znajduje sie w drzewie
   * \retval FALSE Brak elementu o zadanej wartosci 
   */
  bool search(const type elem);
  /*!
   * \brief Metoda print
   *
   * Sluzy do wyswietlenia elementow drzewa na standardowym strumieniu wyjsciowym.
   * Elementy wyswietlane sa w nastepujacej kolejności: korzen, lewe poddrzewo, prawe poddrzewo
   */
  void print();
};

template <class type>
void BinaryTree<type>::insert(const type elem, treenode<type> *leaf){
  if(elem < leaf->val){
    if(leaf->left!=NULL)
      insert(elem, leaf->left);
    else
      leaf->left = new treenode<type>(elem);
  }
  else if(elem >= leaf->val){
    if(leaf->right!=NULL)
      insert(elem, leaf->right);
    else
      leaf->right = new treenode<type>(elem);
  }
}



template <class type>
void BinaryTree<type>::insert(const type elem){
  if(root!=NULL)
    insert(elem, root);
  else
    root = new treenode<type>(elem);
}

template <class type>
bool BinaryTree<type>::remove(const type elem){
  if(root == NULL)
    return false;
  if(elem < root->val)
    root->left = remove(root->left, elem);
  else if(elem > root->val)
    root->right = remove(root->right, elem);
  else{
    if(root->left == NULL){
      treenode<type> *tmp = root;
      root = root->right;
      delete tmp;
      return true;
    }
    else if(root->right == NULL){
      treenode<type> *tmp = root;
      root = root->left;
      delete tmp;
      return true;
    }
    treenode<type> *tmp = findMin(root->right);
    root->val = tmp->val;
    root->right = remove(root->right, tmp->val);
  }
  return true;
}

template <class type>
treenode<type> * BinaryTree<type>::remove(treenode<type> *root, const type elem){
  if(root == NULL)
    return root;
  if(elem < root->val)
    root->left = remove(root->left, elem);
  else if(elem > root->val)
    root->right = remove(root->right, elem);
  else{
    if(root->left == NULL){
      treenode<type> *tmp = root;
      root = root->right;
      delete tmp;
      return root;
    }
    else if(root->right == NULL){
      treenode<type> *tmp = root;
      root = root->left;
      delete tmp;
      return root;
    }
    treenode<type> *tmp = findMin(root->right);
    root->val = tmp->val;
    root->right = remove(root->right, tmp->val);
  }
  return root;
}

template <class type>
bool BinaryTree<type>::search(const type elem){
  treenode<type> *ptr = root;
  while(true){
    if(ptr == NULL)
      return false;    
    else if(elem == ptr->val)
      return true;
    else if(elem < ptr->val)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }
}

template <class type>
void BinaryTree<type>::print(){
  if(root != NULL){
    std::cout << root->val << " ";
    print(root->left);
    print(root->right);
  }
}

template <class type>
void BinaryTree<type>::print(treenode<type> *root){
  if(root != NULL){
    std::cout << root-> val << " ";
    print(root->left);
    print(root->right);
  }
}

template <class type>
treenode<type> * BinaryTree<type>::findMin(treenode<type> *node){
  treenode<type> *ptr = node;
  while(ptr->left != NULL)
    ptr = ptr->left;
  return ptr;
}
#endif
