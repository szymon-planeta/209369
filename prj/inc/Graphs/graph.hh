#ifndef GRAPH_HH
#define GRAPH_HH

#include "ABData/list.hh"
#include "ABData/queue.hh"
#include "ABData/stack.hh"

#include <iostream>

/*!
 * \file
 * \brief Definicja klasy Graph
 */
const int DEFAULT_SIZE=100;

class Graph{
  /*!
   * \brief Licznik wierzcholkow grafu
   */
  int vCount;
 /*!
   * \brief Wskaznik na dynamicznie alokowana tablice list
   */
  List<int> *tab;
private:
  /*!
   * \brief Metoda DFS_visit
   *
   * Metoda pomocnicza dla metody DFS
   */
  void DFS_visit(int u, int time, char *color, int *previous, int *d, int *f);

public:
  /*!
   * \brief Konstruktor bezparametryczny
   */
  Graph(){tab = new List<int> [DEFAULT_SIZE];
    vCount=DEFAULT_SIZE;}
  /*!
   * \brief Konstruktor parametryczny
   *
   * \param[in] c Ilosc wierzcholkow
   */
  Graph(int c){tab = new List<int> [c];
    vCount=c;}
  /*!
   * \brief Metoda insert
   *
   * Wstawia polaczenie miedzy wierzcholkami
   *
   * \param[in] v1 Nr wierzcholka pierwszego
   * \param[in] v2 Nr wierzcholka drugiego
   */
  void insert(int v1, int v2);
  /*!
   * \brief Procedura print
   *
   * Wyswietla graf w formie WIERZCHOLEK | LISTA WIERZCHOLKOW Z KTORYMI JEST POLACZONY
   */
  void print();
  /*!
   * \brief Metoda BFS (Breadth First Search)
   *
   * Metoda przeszukiwania grafu wszerz. Przeszukuje caly graf
   */
  void BFS(int source);
  /*!
   * \brief Metoda BFS (Breadth First Search)
   *
   * Metoda przeszukiwania grafu wszerz. Znajduje sciezke pomiedzy dwoma zadanymi
   * wierzcholkami i wypisuje ja na ekran
   */
  void BFS(int source, int finish);

  /*!
   * \brief Metoda DFS (Depth First Search)
   *
   * Metoda przeszukiwania grafu w glab. Przeszukuje caly graf.
   */
  void DFS();

};

#endif
