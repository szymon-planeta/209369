//benchmark.hh

#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include <iostream>
#include "program.hh"
#include <sys/time.h>
#include <fstream>
#include "kolejka.hh"
/*!
 * \file
 * \brief Definicja klasy Benchmark
 */

using namespace std;

/*!
 * \brief Klasa Benchmark
 * 
 * Jest to klasa służąca do testowania programów.
 */
class Benchmark{
private:
  /*!
   * \brief Zmienne t1, t2
   *
   * Zmienne przechowujace momenty rozpaczecia i zakonczenia pomiaru czasu.
   */
  timeval t1, t2;

  /*!
   * \brief Zmienna czas_pomiaru
   *
   * Przechowuje obliczony czas pojedynczego pomiaru (w ms)
   */
  double czas_pomiaru;

public:
  /*!
   * \brief Procedura rozpocznij_pomiar
   *
   * Rozpoczyna pomiar czasu.
   */
  void rozpocznij_pomiar();

  /*!
   * \brief Procedura zakoncz_pomiar
   *
   * Konczy pomiar czasu i zapisuje wartosc zmierzona w zmiennej czas_pomiaru.
   */
  void zakoncz_pomiar();

  /*!
   * \brief Metoda testuj
   *
   * Dokonuje testow wybranego programu. Dane wczytywane sa do tablicy.
   *
   * \param[in] program Program wybrany do testowania.
   * \param[in] dane Wskaznik na nazwe pliku z danymi.
   * \param[in] ilosc_danych Ilosc danych, ktore chcemy pobrac do testu.
   * \param[in] ilosc_testow Ilosc testow, jakie chcemy przeprowadzic.
   *
   * \return Metoda zwraca sredni czas wykonania programu dla podanych parametrow.
   */
  double testuj(Program &program,char* dane, int ilosc_danych, int ilosc_testow);

  /*!
   * \brief Metoda testuj_strukture
   *
   * Dokonuje testow wybranego programu. Dane wczytywane sa do odpowiedniej
   * struktury.
   *
   * \param[in] program Program wybrany do testowania.
   * \param[in] dane Wskaznik na nazwe pliku z danymi.
   * \param[in] ilosc_danych Ilosc danych, ktore chcemy pobrac do testu.
   * \param[in] ilosc_testow Ilosc testow, jakie chcemy przeprowadzic.
   *
   * \return Metoda zwraca sredni czas wykonania programu dla podanych parametrow.
   */
  double testuj_strukture(Program &program,char* dane, int ilosc_danych, int ilosc_testow);
};

#endif
