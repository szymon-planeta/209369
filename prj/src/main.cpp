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

using namespace std;


int main(){
  Benchmark test;
  SaveToFile saver;
  test.addObs(&saver);
  //BinaryTree<int> object;
    RedBlackTree<int> object;
  for(int i=1; i<=1000000; i*=10)
  test.runBenchmarkSearchTree(&Trees<int>::search, object, i, 10, (char*)"dane2.dat");
  //test.runBenchmarkFillTree(&Trees<int>::insert, object, i, 10, (char*)"dane.dat");
 
  return 0;
}
