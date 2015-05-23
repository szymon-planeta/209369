#ifndef BINARYTREE_HH
#define BINARYTREE_HH 

#include <iostream>
#include <cstdlib>
#include "trees.hh"
#include "tools.hh"
#include <cmath>
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
   * \brief Wskaznik na lewe dziecko
   */
  treenode *left;
  /*!
   * \brief Wskaznik na prawe dziecko
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
   * \brief numberOfNodes - ilosc wezlow w drzewie
   */
  int numberOfNodes;
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

  /*!
   * \brief Metoda rotateLeft
   *
   * Metoda pomocnicza pomocna przy balansowaniu drzewa
   */
  bool rotateLeft(treenode<type> *node);
  /*!
   * \brief Metoda rotateRight
   *
   * Metoda pomocnicza pomocna przy balansowaniu drzewa
   *
   * \param[in] node 
   */
  bool rotateRight(treenode<type> *node);

  /*!
   * \brief Procedura balance
   *
   * Balansuje drzewo
   *
   * \param[in] root Korzen drzewa, ktore chcemy balansowac
   */
  void balance(treenode<type> *root);

  /*!
   * \brief Metoda deleteTree
   *
   * Usuwa drzewa zaczynajace sie w podanym wezle
   *
   * \param[in] node Korzen drzewa, ktore chcemy usunac
   */
  void deleteTree(treenode<type> *node);

  /*!
   * \brief Metoda prywatna height
   * 
   * Znajduje wysokosc poddrzewa rozpoczynajacego sie w zadanym korzeniu
   *
   * \param[in] node Korzen drzewa, ktorego wysokosc chcemy znalezc
   *
   * \return Wysokosc drzewa
   */
  int height(treenode<type> *node);
  
public:
  /*!
   * \brief Konstruktor bezparametryczny
   */
  BinaryTree(){
    numberOfNodes = 0;
    root = NULL;
  }
  /*!
   * \brief Destruktor
   */
  ~BinaryTree(){
    deleteTree(root);
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

  /*!
   * \brief Procedura height
   *
   * \return Zwraca wysokosc calego drzewa
   */
  int height();

  /*!
   * \brief Procedura clear
   *
   * Czysci drzewo, usuwa wszystkie jego wezly
   */
  void clear(){deleteTree(root); root=NULL; }
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
  ++numberOfNodes;
  if(height(root)>2*log2(numberOfNodes)) //USTAWIONO 2
    balance(root);
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

template <class type>
bool BinaryTree<type>::rotateLeft(treenode<type> *node){
  treenode<type> *ptr; 
  if(node==NULL || node->right==NULL)
    return false;
  ptr=node->right;
  node->right=ptr->right;
  ptr->right=ptr->left;
  ptr->left=node->left;
  node->left=ptr;
 
  substitute(node->val, ptr->val);
  return true;
}
template<class type>
bool BinaryTree<type>::rotateRight(treenode<type> *node){
  treenode<type> *ptr;
  if(node==NULL || node->left==NULL)
    return false;
  ptr=node->left;
  node->left=ptr->left;
  ptr->left=ptr->right;
  ptr->right=node->right;
  node->right=ptr;
 
  substitute(node->val, ptr->val);
  return true;
}

template <class type>
void BinaryTree<type>::balance(treenode<type> *root){
  treenode<type> *ptr; 
  int nodecount, i;
  for(ptr=root, nodecount=0; ptr!=NULL; ptr=ptr->right, ++nodecount)
    while(rotateRight(ptr)==true)
      {}
  for(i=nodecount/2; i>0; i/=2){
    int j;
    for(ptr=root, j=0; j<i; ++j, ptr=ptr->right)
      rotateLeft(ptr);
  }      
}

template <class type>
void BinaryTree<type>::deleteTree(treenode<type> *node){
  if(node){
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

template <class type>
int BinaryTree<type>::height(treenode<type> *node){
  if(node==NULL) 
    return 0;
  return 1+max(height(node->left),height(node->right));
}

template <class type>
int BinaryTree<type>::height(){
  return height(root);
}
#endif
