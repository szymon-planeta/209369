#include "benchmark.hh"
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
  std::cout << total << "  " << amount << "    " << std::endl;
  mean=total/counter;
  notify();
}

