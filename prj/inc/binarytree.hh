#ifndef BINARYTREE_HH
#define BINARYTREE_HH 

#include <iostream>
#include <cstdlib>
#include "node.hh"
#include "list.hh"

template <typename type>
struct treenode{
  type val;
  treenode *left;
  treenode *right;

  treenode(type elem){
    val = elem;
    left = NULL;
    right = NULL;
  }
};


template <class type>
class BinaryTree{
  treenode<type> *root;
  
private:
  void insert(type elem, treenode<type> *leaf);

public:
  BinaryTree(){
    root = NULL;
  }

  void insert(type elem);

  void display();
  

};

template <class type>
void BinaryTree<type>::insert(type elem, treenode<type> *leaf){
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
void BinaryTree<type>::insert(type elem){
  if(root!=NULL)
    insert(elem, root);
  else
    root = new treenode<type>(elem);
}

template <class type>
void BinaryTree<type>::display(){
    treenode<type> *ptr = root;
    while(ptr!=NULL){
      std::cout<<ptr->val<<std::endl;
      ptr=ptr->right;
    }
}

#endif
