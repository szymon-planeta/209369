#include "list.hh"
#include "stack.hh"
#include "queue.hh"
#include "iterable.hh"
#include "timer.hh"
#include "benchmark.hh"
#include "observer.hh"

using namespace std;

template<typename type>
void insertsort(Iterable<type> &tosort, int right){
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
  Timer a;
  a.start_timer();
  Queue<int> stos;
  //Stack<int> stos;
  for(int i=10; i>=0; i--)
    stos.push(i);
  //stos.pop();
  // stos.display();
  //stos[1]=10000;
  //cout<<stos[100];
  //stos.display();
  insertsort(stos, stos.size()-1);
  //stos.display();
  a.stop_timer();
  cout<<a.getTime()<<endl;
  return 0;
}
