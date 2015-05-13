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
  int dataNumber;
public:
  Benchmark(){
    total = 0;
    mean = 0;
    counter = 0;
    dataNumber = 0;
  }
  /*!
   * \brief Wysyla powiadomienie do obserwatorow
   */
  void notify();
  /*!
   * \brief Konczy pomiar czasu
   *
   * Zapisuje moment zakonczenia pomiaru do zmiennej end, oblicza zmierzony
   * czas i zapisuje do zmiennej time, zwieksza counter o 1.
   */
  void stop_Ctimer();

  /*!
   * \brief Oblicza srednia
   *
   * Dzieli sume pomiarow przez ich liczbe i zapisuje do zmiennej mean.
   */
  void calc_mean();

  /*!
   * \brief Wykonuje zadana ilosc testow zadanej funkcji dla zadanej ilosc danych
   *
   * \param[in] Zadawana funkcja
   * \param[in] Ilosc danych
   * \param[in] Ilosc testow
   */
  //template<typename type>
  void runBenchmark(void (*f)(Stack<int>&, int), Stack<int> &container, int dataCount, int repeats);

};

#endif
