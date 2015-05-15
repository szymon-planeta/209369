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
  /*!
   * \brief Zmienna przechowuje calkowity czas testow
   */
  double total;
  /*!
   * \brief Zmienna przechowuje sredni czas testow
   */
  double mean;
  /*!
   * \brief Zmienna przechowuje licznik wykonanych testow
   */
  int counter;
  /*!
   * \brief Zmienna przechowuje ilosc danych, jaka aktualnie jest testowana
   */
  int amount;
public:
  Benchmark(){
    total = 0;
    mean = 0;
    counter = 0;
    amount = 0;
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
   * Dzieli sume pomiarow przez ich liczbe i zapisuje do zmiennej mean. Wysyla powiadomienie do obserwatorow.
   */
  void calc_mean();

  /*!
   * \brief Wykonuje zadana ilosc testow zadanej funkcji dla zadanej ilosc danych
   *
   * \param[in] Zadawana funkcja
   * \param[in] Ilosc danych
   * \param[in] Ilosc testow
   */
  template<typename type>
  void runBenchmarkSort(void (*f)(Iterable<type>&, int, int), Iterable<type> &container, int dataCount, int repeats);

};

template<typename type>
void Benchmark::runBenchmarkSort(void (*f)(Iterable<type>&, int, int), Iterable<type> &container, int dataCount, int repeats){
  amount = dataCount;
  for(int i=1; i<=repeats; i++){
    start_timer();
    (*f)(container, 0, amount-1);
    stop_Ctimer();
  }
  calc_mean();
}

#endif
