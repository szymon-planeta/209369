#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "observer.hh"
#include "timer.hh"
#include "Trees/trees.hh"
#include <cstdlib>
#include <ctime>

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

 /*!
   * \brief Wykonuje zadana ilosc testow zadanej funkcji na zadanym obiekcie dla zadanej ilosc danych
   *
   * \param[in] *f Zadawana funkcja wypelniajaca
   * \param[in] container Drzewo, ktore chcemy testowac
   * \param[in] dataCount Ilosc danych
   * \param[in] repeats Ilosc testow
   */
  template<typename type>
  void runBenchmarkFillTree(void (Trees<type>::*f)(type), Trees<type> &tree, int dataCount, int repeats, char* dataFile);

/*!
   * \brief Wykonuje zadana ilosc testow zadanej funkcji na zadanym obiekcie dla zadanej ilosc danych
   *
   * \param[in] *f Zadawana funkcja szukajaca
   * \param[in] container Drzewo, ktore chcemy testowac
   * \param[in] dataCount Ilosc danych
   * \param[in] repeats Ilosc testow
   */
  template<typename type>
  void runBenchmarkSearchTree(bool (Trees<type>::*f)(type), Trees<type> &tree, int dataCount, int repeats, char* dataFile);
};

template<typename type>
void Benchmark::runBenchmarkFillTree(void (Trees<type>::*f)(type), Trees<type> &tree, int dataCount, int repeats, char* dataFile){
  amount = dataCount;
  total=0; 
  mean=0;
  counter=0;
  ifstream input;
  input.open(dataFile);
  type tmp;
  for(int i=1; i<=repeats; i++){
    tree.clear();
    
    for(int j=1; j<=dataCount-1; j++){
      input >> tmp;
      (tree.*f)(tmp);
    }
    start_timer();
    input >> tmp;
    (tree.*f)(tmp);
    stop_Ctimer();
  }
  calc_mean();
  input.close();
}

template<typename type>
void Benchmark::runBenchmarkSearchTree(bool (Trees<type>::*f)(type), Trees<type> &tree, int dataCount, int repeats, char* dataFile){
  amount = dataCount;
  total=0; 
  mean=0;
  counter=0;
  ifstream input;
  input.open(dataFile);
  type tmp;
  for(int j=1; j<=dataCount; j++){
    input >> tmp;
    tree.insert(tmp);
  }
  input.close();
  srand(time(NULL));
  for(int i=1; i<=repeats; i++){
    //for(int j=1; j<=dataCount-1; j++)
    //   (tree.*f)(48830);
    start_timer();
    (tree.*f)(48830);
    stop_Ctimer();
  }
  calc_mean();
}


#endif
