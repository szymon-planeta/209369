#include "list.hh"
#include "stack.hh"
#include "queue.hh"
#include "iterable.hh"
#include "timer.hh"
#include "benchmark.hh"
#include "observer.hh"

using namespace std;

//template<typename type>
void insertsort(Stack<int> &tosort, int right){
//void insertsort(Iterable<int> &tosort, int right){
  int i,j; int temp;
  for(i=1; i<=right; ++i){
    temp=tosort[i];
    for(j=i; j>0 && temp<tosort[j-1]; --j)
      tosort[j] = tosort[j-1];
    tosort[j]=temp;
  }
}


int main(){
  //List<int> lista;
  Benchmark test;
  SaveToFile saver;
  test.addObs(&saver);
  //Queue<int> stos;
  Stack<int> stos;
  for(int i=0; i<=10; i++)
    stos.push(i);
  //stos.pop();
  // stos.display();
  //stos[1]=10000;
  //cout<<stos[100];
  stos.display();
  test.runBenchmark(&insertsort, stos, 11, 10);
  // insertsort(stos, stos.size()-1);
  stos.display();

  return 0;
}
