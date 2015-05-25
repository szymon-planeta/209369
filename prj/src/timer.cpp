#include "Benchmark/timer.hh"
#include <cstdlib>

/*!
 * \file
 * \brief Ciala metod klasy Timer
 */
void Timer::start_timer(){
  gettimeofday(&start, NULL);

}
 
void Timer::stop_timer(){
  gettimeofday(&end, NULL);
  atime = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
  atime += (end.tv_usec - start.tv_usec) / 1000.0;   // us to ms
}
 
double Timer::getTime(){
  return atime;
}
