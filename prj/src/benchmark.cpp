#include "Benchmark/benchmark.hh"
#include <cstdlib>
#include <iostream>
/*!
 * \file
 * \brief Ciala metod klasy Benchmark
 */
void Benchmark::notify(){
  for(unsigned int i=0; i<obss.size();i++)
    obss[i]->update(amount, mean);
}

void Benchmark::stop_Ctimer(){
  stop_timer();
  total+=atime;
  counter++;
}

void Benchmark::calc_mean(){
  mean=total/counter;
  std::cout << mean << "  " << amount << "    " << std::endl;
  notify();
}

template<typename type>
void Benchmark::runBenchmarkSort(void (*f)(Iterable<type>&, int, int), Iterable<type> &container, int dataCount, int repeats){
  amount = dataCount;
  total=0; 
  mean=0;
  counter=0;
  for(int i=1; i<=repeats; i++){
    start_timer();
    (*f)(container, 0, amount-1);
    stop_Ctimer();
  }
  calc_mean();
}

void Benchmark::runBenchmarkSearchGraph(void (Graph::*f)(), Graph graph, int dataCount, int repeats){
  amount = dataCount;
  total=0; 
  mean=0;
  counter=0;

  /* DANE - spojny losowy (*/
  if(dataCount>1)
    graph.insertE(0, 1);
  for(int j=1; j<dataCount; j++)
    graph.insertE(j, rand()%j);
  /* DANE - 0 ze wszystkimi 
     for(int j=0; j<dataCount; j++)
     graph.insertE(0,j);*/
  /* DANE - LISTA 
     for(int j=0; j<=dataCount-2; j++){
     graph.insertE(j, j+1);
     }*/
  for(int i=1; i<=repeats; i++){
    start_timer();
    (graph.*f)();
    stop_Ctimer();
  }
  calc_mean();
}



