#include "benchmark.hh"
#include <cstdlib>
#include <iostream>
/*!
 * \file
 * \brief Ciala metod klasy Benchmark
 */
void Benchmark::notify(){
  for(unsigned int i=0; i<obss.size();i++)
    obss[i]->update(dataNumber, mean);
}

void Benchmark::stop_Ctimer(){
  stop_timer();
  total+=time;
  counter++;
}

void Benchmark::calc_mean(){
  std::cout << total << "  " << counter << "    " << std::endl;
  mean=total/counter;
  notify();
}

//NA TEMPLATE
//template<typename type>
void Benchmark::runBenchmark(void (*f)(Stack<int>&, int), Stack<int> &container, int dataCount, int repeats){
  dataNumber = dataCount;
  for(int i=1; i<=repeats; i++){
    start_timer();
    (*f)(container, dataCount-1);
    stop_Ctimer();
  }
  calc_mean();
}

