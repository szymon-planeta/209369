#include "list.hh"
#include "stack.hh"
#include "queue.hh"
#include "iterable.hh"
#include "timer.hh"
#include "benchmark.hh"
#include "observer.hh"
#include "sorts.hh"
#include "abdatatools.hh"
#include "listarray.hh"
#include "assoctab.hh"

using namespace std;


int main(){
  //ListArray<int> object;
  Benchmark test;
  SaveToFile saver;
  test.addObs(&saver);
  /* 
  for(int i=10; i<=1000000; i*=10){
    fillFromFile(&object, i, "dane.dat");
    test.runBenchmarkSort(&quicksort, object, object.size(), 20);
    clear(&object);
    }
  */
  AssocTab<string, string> object;
  object["kon"] = "rafal";
  cout << object["kon"] << endl;
  object.pop("kon");

  return 0;
}
