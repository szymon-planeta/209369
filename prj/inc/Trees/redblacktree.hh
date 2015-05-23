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
  char color;
  /*!
   * \brief Konstruktor parametryczny
   *
   * Tworzy wezel o podanej wartosci ze wskaznikami ustawionymi na NULL
   *
   * \param[in] elem Zadana wartosc
   */
  rbtreenode(type elem){val=elem; left=NULL; right=NULL; color='b';}
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

  /*!
   * \brief Metoda pomocnicza przy wypisaniu drzewa
   */
  void print(rbtreenode<type> *root);
  /*!
   * \brief Metoda pomocnicza przy usuwaniu zadanej wartosci z drzewa
   */
  rbtreenode<type> * remove(rbtreenode<type> *root, const type elem);
  /*!
   * \brief Inicjuje wezel zadana wartoscia, wskazniki left i right ustawia na sentinel
   */
  void init(rbtreenode<type> *toInit, type data);
  /*!
   * \brief Znajduje odpowiedniego rodzica dla zadanej wartosci
   *
   * \param[in] data Wartosc, dla ktorej poszukujemy wezla rodzica
   *
   * \retval Znaleziony wezel rodzic
   */
  rbtreenode<type>* findSuitableParent(type data);
  /*!
   * \brief Tworzy odpowiednie relacje ojca-syna pomiedzy podanymi wezlami
   *
   * \param[in] parent Wezel ojciec
   * \param[in] child Wezel syn
   */
  void createBindings(rbtreenode<type> *parent, rbtreenode<type> *child);
  /*!
   * \brief Znajduje najmniejsza wartosc w poddrzewie rozpoczynajacym sie w podanym wezle
   *
   * \param[in] node Korzen poddrzewa, w ktorym znaleziona zostanie najmniejsza wartosc
   */
  rbtreenode<type> * findMin(rbtreenode<type> *node);
  /*!
   * \brief Ustawia podany element jako nowy korzen
   *
   * \param[in] elem Nowy korzen
   */
  void setNewRoot(rbtreenode<type> *elem);
  /*!
   * \brief Dokonuje rotacji w prawo
   */
  void rotateRight(rbtreenode<type> *elem);
/*!
   * \brief Dokonuje rotacji w lewo
   */
  void rotateLeft(rbtreenode<type> *elem);
  
  void correct(rbtreenode<type> *elem);
  void correctLeft(rbtreenode<type> *elem);
  void correctRight(rbtreenode<type> *elem);

  /*!
   * \brief Metoda deleteTree
   *
   * Usuwa drzewa zaczynajace sie w podanym wezle
   *
   * \param[in] node Korzen drzewa, ktore chcemy usunac
   */
  void deleteTree(rbtreenode<type> *node);
  
public: 
  /*!
   * \brief Konstruktor bezparametryczny
   */
  RedBlackTree(){
    root = NULL;
    sentinel = new rbtreenode<type>(type());
    sentinel->color = 'b';
    sentinel->left = NULL;
    sentinel->right = NULL;
  }
  /*!
   * \brief Destruktor
   */
  ~RedBlackTree(){
    deleteTree(root);
  }
  /*!
   * \brief Metoda insert
   *
   * Sluzy do wstawienia zadanego elementu w odpowniednie miejsce drzewa
   *
   * \param[in] elem Wartosc do wstawienia
   */
  void insert(const type data);
  /*!
   * \brief Metoda usuwajaca wezel o zadanej wartosci z drzewa
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
   * \brief Procedura clear
   *
   * Czysci drzewo, usuwa wszystkie jego wezly
   */
  void clear(){deleteTree(root); root=NULL;}

};
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::insert(const type data){
  rbtreenode<type> *elem = new rbtreenode<type>(type());
  init(elem, data);
  rbtreenode<type> *parent = findSuitableParent(data);
  createBindings(parent, elem);
  correct(elem);
}
/*****************************************/

/*****************************************/
template <class type>
bool RedBlackTree<type>::search(const type elem){
  rbtreenode<type> *ptr = root;
  while(true){
    if(ptr == NULL || ptr == sentinel)
      return false;    
    else if(elem == ptr->val)
      return true;
    else if(elem < ptr->val)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }
}
/*****************************************/

/*****************************************/
template <class type>
bool RedBlackTree<type>::remove(const type elem){
  if(root == NULL || root == sentinel)
    return false;
  if(elem < root->val)
    root->left = remove(root->left, elem);
  else if(elem > root->val)
    root->right = remove(root->right, elem);
  else{
    if(root->left == NULL || root->left == sentinel){
      rbtreenode<type> *tmp = root;
      root = root->right;
      delete tmp;
      return true;
    }
    else if(root->right == NULL || root->right == sentinel){
      rbtreenode<type> *tmp = root;
      root = root->left;
      delete tmp;
      return true;
    }
    rbtreenode<type> *tmp = findMin(root->right);
    root->val = tmp->val;
    root->right = remove(root->right, tmp->val);
  }
  return true;
}
/*****************************************/

/*****************************************/
template <class type>
rbtreenode<type> * RedBlackTree<type>::remove(rbtreenode<type> *root, const type elem){
  if(root == NULL || root == sentinel)
    return root;
  if(elem < root->val)
    root->left = remove(root->left, elem);
  else if(elem > root->val)
    root->right = remove(root->right, elem);
  else{
    if(root->left == NULL || root->left == sentinel){
      rbtreenode<type> *tmp = root;
      root = root->right;
      delete tmp;
      return root;
    }
    else if(root->right == NULL || root->right == sentinel){
      rbtreenode<type> *tmp = root;
      root = root->left;
      delete tmp;
      return root;
    }
    rbtreenode<type> *tmp = findMin(root->right);
    root->val = tmp->val;
    root->right = remove(root->right, tmp->val);
  }
  return root;
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::print(){
  if(root != NULL && root != sentinel){
    std::cout << root->val << " ";
    print(root->left);
    print(root->right);
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::print(rbtreenode<type> *root){
  if(root != NULL && root != sentinel){
    std::cout << root-> val << " ";
    print(root->left);
    print(root->right);
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::init(rbtreenode<type> *toInit, type data){
  toInit->color = 'r';
  toInit->val = data;
  toInit->right = sentinel;
  toInit->left = sentinel;
}
/*****************************************/

/*****************************************/
template <class type>
rbtreenode<type>* RedBlackTree<type>::findSuitableParent(type data){
  rbtreenode<type> *parent = NULL;
  rbtreenode<type> *x = root;
  while(x != NULL){
    if(x != sentinel){
      parent = x;
      if(data < x->val)
	x = x->left;
      else
	x = x->right;
    }
    else
      break;
  }
  return parent;
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::rotateRight(rbtreenode<type> *elem){
  if(elem != NULL && elem != sentinel){
    if(elem->left != sentinel){
      rbtreenode<type> *tmp = elem->left;
      elem->left = tmp->right;
      tmp->right->parent = elem;
      tmp->right = elem;
      if(elem->parent != NULL){
	if(elem->parent->left == elem)
	  elem->parent->left = tmp;
	else
	  elem->parent->right = tmp;
	tmp->parent = elem->parent;
      }
      elem->parent = tmp;
      if(elem == root)
	setNewRoot(tmp);
    }
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::rotateLeft(rbtreenode<type> *elem){
  if(elem != NULL && elem != sentinel){
    if(elem->right != sentinel){
      rbtreenode<type> *tmp = elem->right;
      elem->right = tmp->left;
      tmp->left->parent = elem;
      tmp->left = elem;
      if(elem->parent != NULL){
	if(elem->parent->left == elem)
	  elem->parent->left = tmp;
	else
	  elem->parent->right = tmp;
	tmp->parent = elem->parent;
      }
      elem->parent = tmp;
      if(elem == root)
	setNewRoot(tmp);
    }
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::setNewRoot(rbtreenode<type> *elem){
  elem->parent = sentinel;
  elem->color = 'b';
  root = elem;
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::createBindings(rbtreenode<type> *parent, rbtreenode<type> *child){
  if(parent == NULL){
    child->parent = NULL;
    root = child;
    root->color = 'b';
  }
  else{
    child->parent = parent;
    if(child->val >= parent->val)
      parent->right = child;
    else
      parent->left = child;
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::correct(rbtreenode<type> *elem){
  while(elem != root && elem->parent->color == 'r'){
    if(elem->parent == elem->parent->parent->left)
      correctLeft(elem);
    else
      correctRight(elem);
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::correctLeft(rbtreenode<type> *elem){
  if(elem->parent->parent->right->color == 'r'){
    elem = elem->parent->parent;
    elem->right->color = 'b';
    elem->left->color = 'b';
    if(elem != root)
      elem->color = 'r';
    correct(elem);
  }
  else{
    if(elem == elem->parent->right){
      rotateLeft(elem->parent);
      rotateRight(elem->parent);
      elem->color = 'b';
      elem->left->color = 'r';
      elem->right->color = 'r';
    }
    else{
      rotateRight(elem->parent->parent);
      elem = elem->parent;
      elem->color = 'b';
      elem->left->color = 'r';
      elem->right->color = 'r';
    }
  }
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::correctRight(rbtreenode<type> *elem){
  if(elem->parent->parent->left->color == 'r'){
    elem = elem->parent->parent;
    elem->right->color = 'b';
    elem->left->color = 'b';
    elem->color = 'r';
    correct(elem);
  }
  else{
    if(elem == elem->parent->left){
      elem = elem->parent;
      rotateRight(elem);
    }
    elem->parent->color = 'b';
    elem->parent->parent->color = 'r';
    rotateLeft(elem->parent->parent);
  }
  root->color = 'b';
}
/*****************************************/

/*****************************************/
template <class type>
rbtreenode<type> * RedBlackTree<type>::findMin(rbtreenode<type> *node){
  rbtreenode<type> *ptr = node;
  while(ptr->left != NULL && ptr->left != sentinel)
    ptr = ptr->left;
  return ptr;
}
/*****************************************/

/*****************************************/
template <class type>
void RedBlackTree<type>::deleteTree(rbtreenode<type> *node){
  if(node && node!=sentinel){
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}
#endif
