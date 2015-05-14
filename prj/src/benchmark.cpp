#include "benchmark.hh"
#include <cstdlib>
#include <iostream>
/*!
 * \file
 * \brief Ciala metod klasy Benchmark
 */
template<class type>
void Benchmark::notify(){
  for(unsigned int i=0; i<obss.size();i++)
    obss[i]->update(dataNumber, mean);
}

template<class type>
void Benchmark::stop_Ctimer(){
  stop_timer();
  total+=time;
  counter++;
}

template<class type>
void Benchmark::calc_mean(){
  std::cout << total << "  " << counter << "    " << std::endl;
  mean=total/counter;
  notify();
}

//NA TEMPLATE
template<class type>
void Benchmark::runBenchmark(void (*f)(Iterable<type>&, int), Iterable<type> &container, int dataCount, int repeats){
  dataNumber = dataCount;
  for(int i=1; i<=repeats; i++){
    start_timer();
    (*f)(container, dataCount-1);
    stop_Ctimer();
  }
  calc_mean();
}

