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

  
  Benchmark test;
  SaveToFile saver;
  test.addObs(&saver);
  

  for(int i=1; i<=1000000; i*=10){
    Graph object(i);
    test.runBenchmarkSearchGraph(&Graph::DFS, object, i, 3);
  }
 
  /*  object.insertE(0,1);  
      object.insertE(0,2);
      object.insertE(1,3);  
      object.insertE(1,4);
      object.insertE(2,4);
      object.insertE(2,5);
      object.insertE(2,6);
      object.insertE(3,3);
      object.insertE(3,6);
  object.insertE(4,6);
  object.insertE(5,7);
  object.insertE(7,8)
  object.print();
  object.BFS();
  object.DFS();*/



 
  return 0;
}
