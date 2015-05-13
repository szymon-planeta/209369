#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "observer.hh"
#include "timer.hh"

/*!
 * \file
 * \brief Definicja klasy Benchmark
 */

/*!
 * \brief Klasa Benchmark
 * 
 * Jest to klasa służąca do testowania programów.
 */
class Benchmark: public Subject, public Timer{
  double total;
  double mean;
  int counter;
public:
  /*!
   * \brief Konczy pomiar czasu
   *
   * Zapisuje moment zakonczenia pomiaru do zmiennej end, oblicza zmierzony
   * czas i zapisuje do zmiennej time, zwieksza counter o 1.
   */
  void stop_Ctimer(){
    stop_timer();
    counter++;
  }

  double calc_mean(){
    mean=total/counter;
    notify();
    return mean;
  }

  double getCounter(){
    return counter;
  }
};

#endif
