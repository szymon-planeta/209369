#include "list.hh"
#include "stack.hh"
#include "queue.hh"
#include "iterable.hh"
#include "timer.hh"
#include "benchmark.hh"
#include "observer.hh"
#include "sorts.hh"
#include "abdatatools.hh"

using namespace std;

int main(){
  Stack<int> object;
  Benchmark test;
  SaveToFile saver;
  test.addObs(&saver);
  for(int i=10; i<=10000; i*=10){
    fillFromFile(&object, i, "dane.dat");
    test.runBenchmarkSort(&insertsort, object, object.size(), 10);
    clear(&object);
  }
  return 0;
}
