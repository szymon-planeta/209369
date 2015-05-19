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
  total+=time;
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
