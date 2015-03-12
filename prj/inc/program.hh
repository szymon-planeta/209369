//program.hh

#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <fstream>
#include <iostream>

using namespace std;

/*!
 * \file
 * \brief Definicja klasy Program
 */

/*!
 * \brief Modeluje klase Program.
 *
 * Klasa Program zawiera zmienne oraz metody wspolne dla wszystkich programow.
 * Sa one zwiazane z przechowywaniem i obsluga danych.
 */
class Program{
protected:
  /*!
   * \brief Zmiena rozmiar_tab
   *
   * Zmienna przechowujaca informacje o ilosci wczytanych danych,
   * ktora rowna jest dlugosci utworzonej tablicy dynamicznej (wskazywanej
   * wskaznikiem tab).
   */
  int rozmiar_tab;

  /*!
   * \brief Zmienna tablica
   *
   * Zamienna wskaznikowa wskazujaca na dynamicznie tworzona
   * tablice z danymi.
   */
  int *tab;

  /*!
   * \brief Zmienna plik_we
   *
   * Zmienna przechowujaca strumien wejsciowy do otwartego pliku z wczytywanymi
   * danymi.
   */
  ifstream plik_we;

  /*!
   * \brief Zmienna plik_wy
   *
   * Zmienna przechowujaca strumien wyjsciowy do tworzonego pliku z danymi
   * po przetworzeniu.
   */
  ofstream plik_wy;

public:
  /*!
   * \brief Akcesor getRozmiar_tab
   *
   * Metoda dajaca mozliwosc odczytu rozmiaru tablicy.
   */
  int getRozmiar_tab(){return rozmiar_tab;}

  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Przypisuje domyslna wartosc 0 dla rozmiaru tablicy danych oraz 
   * NULL dla wskaznika.
   */
  Program(){rozmiar_tab=0;tab=NULL;}

  /*!
   * \brief Destruktor
   *
   * Usuwa dynamicznie utworzona tablice danych oraz przypisuje wskaznikowi
   * wartosc NULL.
   */
  ~Program(){delete[] tab; tab=NULL;}

   /*!
   * \brief Metoda wczytaj_dane
   *
   * Wczytuje dane z pliku. W pierwszej linii pliku musi znajdowac sie informacja
   * o ilosci wczytywanych danych, dane w kolejnych liniach:
   * ilosc_danych
   * dana1
   * dana2
   * ...
   *
   * \param[in] nazwa_pliku Wskaznik do nazwy pliku do wczytania.
   *
   * \retval TRUE Poprawnie wczytano plik.
   * \retval FALSE Blad podczas wczytywania pliku.
   */
  bool wczytaj_dane(char* nazwa_pliku);

 /*!
   * \brief Metoda wczytaj_dane
   *
   * Wczytuje okreslona liczbe danych z pliku. W pierwszej linii pliku musi znajdowac sie informacja
   * o ilosci wczytywanych danych, dane w kolejnych liniach:
   * ilosc_danych
   * dana1
   * dana2
   * ...
   *
   * \param[in] nazwa_pliku Wskaznik do nazwy pliku do wczytania.
   * \param[in] ile_danych Ilosc danych, jakie chcemy wczytac.
   *
   * \retval TRUE Poprawnie wczytano plik.
   * \retval FALSE Blad podczas wczytywania pliku.
   */
  bool wczytaj_dane(char* nazwa_pliku, int ile_danych);

  /*!
   * Metoda zapisz_dane
   *
   * Zapisuje przetworzone dane do pliku. W pierwszej linijce zamieszcza informacje
   * o ilosci danych, w kolejnych liniach pojedyncze dane:
   * ilosc_danych
   * dana1
   * dana2
   * ...
   *
   * \param[in] nazwa_pliku Wskaznik do nazwy pliku do zapisu.
   *
   * \retval TRUE Poprawnie zapisano plik.
   * \retval FALSE Blad podczas zapisu pliku.
   */
 bool zapisz_dane(char* nazwa_pliku);

  /*!
   * \brief Procedura wyswietl_dane
   *
   * Wypisuje wczytane dane jedna pod druga na standardowy strumien wyjscia.
   */
  void wyswietl_dane();

   /*!
   * \brief Wirtualna metoda wykonaj_program
   *
   * Wykonuje program na zadanej liczbie danych.
   */
  virtual bool wykonaj_program();
};

#endif
