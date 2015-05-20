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
    
  RedBlackTree<int> object;
  object.insert(5); object.insert(6);

  object.print();

  /*for(int i=0; i<=11; i++)
    object.insert(i);

  object.print();
  for(int i=0; i<=7; i++)
    object.remove(i);

  cout<<endl;
  object.print();*/
  return 0;

}
