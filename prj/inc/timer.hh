#ifndef TIMER_HH
#define TIMER_HH

#include <sys/time.h>

/*!
 * \file
 * \brief Klasa Timer
 *
 * Służy do pomiaru czasu
 */
class Timer{
  /*!
   * \brief Zmienne start, end
   *
   * Przechowuja informacje o poczatku i koncu pomiaru czasu
   */
  timeval start, end;

  /*!
   * \brief Zmienna time
   *
   * Przechowuje zmierzony czas
   */
  double time;

public:
  /*!
   * \brief Konstruktor bezparametryczny
   */
  Timer(){time=0;}
  /*!
   * \brief Zapisuje moment rozpoczecia pomiaru do zmiennej start.
   */
  void start_timer();
  /*!
   * \brief Konczy pomiar czasu
   *
   * Zapisuje moment zakonczenia pomiaru do zmiennej end, oblicza zmierzony
   * czas i zapisuje do zmiennej time.
   */
  void stop_timer();

  /*!
   * \brief Akcesor do zmiennej time
   *
   * \return Zwraca wartosc zmiennej time
   */
  double getTime();
};

#endif
