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

using namespace std;


int main(){
  
  BinaryTree<int> object;

  for(int i=0; i<=11; i++)
    object.insert(i);

  object.print();
  for(int i=0; i<=7; i++)
    object.remove(i);

  cout<<endl;
  object.print();
  return 0;
}
