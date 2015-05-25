#include "ABData/list.hh"
#include "ABData/stack.hh"
#include "ABData/queue.hh"
#include "ABData/iterable.hh"
#include "Benchmark/timer.hh"
#include "Benchmark/benchmark.hh"
#include "Benchmark/observer.hh"
#include "Trees/binarytree.hh"
#include "ABData/sorts.hh"
#include "ABData/abdatatools.hh"
#include "ABData/listarray.hh"
#include "assoctab.hh"
#include "Trees/redblacktree.hh"
#include "Graphs/graph.hh"

using namespace std;


int main(){

  
  Graph<int> object(9);

  object.insert(0,1);  
  object.insert(0,2);
  object.insert(1,3);  
  object.insert(1,4);
  object.insert(2,4);
  object.insert(2,5);
  object.insert(2,6);
  object.insert(3,3);
  object.insert(3,6);
  object.insert(4,6);
  object.insert(5,7);
  object.insert(7,8);

  object.print();

  object.search(0,8);


  Benchmark test;
  SaveToFile saver;
  test.addObs(&saver);
  // BinaryTree<int> object;
  RedBlackTree<int> object;
  //for(int i=1; i<=10000000; i*=10)
    // test.runBenchmarkSearchTree(&Trees<int>::search, object, i, 10, (char*)"dane.dat");
  // test.runBenchmarkFillTree(&Trees<int>::insert, object, i, 10, (char*)"dane.dat");
 
  return 0;
}
