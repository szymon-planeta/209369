#ifndef GRAPH_HH
#define GRAPH_HH

#include "ABData/list.hh"
#include "ABData/listarray.hh"

#include <iostream>

const int DEFAULT_SIZE=100;

template <class type>
class Graph{
  int vCount;
 /*!
   * \brief Wskaznik na dynamicznie alokowana tablice list
   */
  List<int> *tab;

  type *data;

public:
  Graph(){tab = new List<type> [DEFAULT_SIZE];
    data = new type [DEFAULT_SIZE];
    vCount=DEFAULT_SIZE;}

  Graph(int c){tab = new List<type> [c];
    data = new type [c];
    vCount=c;}

  void insert(int v1, int v2);
  void print();
  bool search(int vBegin, int vEnd);

};

template <class type>
void Graph<type>::insert(int v1, int v2){
  tab[v1].push(v2);
  if(v1!=v2)
    tab[v2].push(v1);
}

template <class type>
void Graph<type>::print(){
  for(int i=0; i<vCount; i++){
    std::cout<<i<<" | ";
    for(int j=0; j<tab[i].size();j++)
      std::cout<<(tab[i])[j] << " ";
    std::cout<<std::endl;
  }
}

template <class type>
bool Graph<type>::search(int vBegin, int vEnd){
  /* ListArray<int> path(vCount);
  for(int i=0; i<tab[i].size(); i++)
    if(data[i].visited==false){
      data[i].visited=true;
      path.push(i);
      search(i,vEnd)
      }*/
  return false;
}

#endif
