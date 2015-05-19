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
   * \brief total Zmienna przechowuje calkowity czas testow
   */
  double total;
  /*!
   * \brief mean Zmienna przechowuje sredni czas testow
   */
  double mean;
  /*!
   * \brief counter Zmienna przechowuje licznik wykonanych testow
   */
  int counter;
  /*!
   * \brief amountZmienna przechowuje ilosc danych, jaka aktualnie jest testowana
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
   * \brief Wykonuje zadana ilosc testow zadanej funkcji sortujacej na zadanym obiekcie dla zadanej ilosc danych
   *
   * \param[in] *f Zadawana funkcja sortujaca
   * \param[in] container Stuktura, ktora chcemy posortowac
   * \param[in] dataCount Ilosc danych
   * \param[in] repeats Ilosc testow
   */
  template<typename type>
  void runBenchmarkSort(void (*f)(Iterable<type>&, int, int), Iterable<type> &container, int dataCount, int repeats);
};



#endif
