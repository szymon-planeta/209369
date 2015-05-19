#ifndef SORTS_HH
#define SORTS_HH

#include "iterable.hh"
#include "tools.hh"

/*!
 * \file
 * \brief W pliku znajduja sie definicje metod sortujacych obiekty dziedziczace
 * z klasy Iterable - takie ktore maja zdefiniowane operatory indeksowania [].
 * Przykladowe wywolanie metody sortujace caly obiekt:
 * Stack stos;
 * insertsort(stos, stos.size()-1)
 */

/*!
 * \brief Sortowanie przez wstawianie
 *
 * Dokonuje sortowania obiektu stosujac metode sortowania przez wstawianie
 *
 * \param[in] &tosort Referencja do obiektu typu Iterable, ktory chcemy posortowac
 * \param[in] left Poczatek zakresu sortowania
 * \param[in] right Koniec zakresu sortowania 
 */
template<typename type>
void insertsort(Iterable<type> &tosort, int left, int right){
  int i,j; int temp;
  for(i=left; i<=right; ++i){
    temp=tosort[i];
    for(j=i; j>left && temp<tosort[j-1]; --j)
      tosort[j] = tosort[j-1];
    tosort[j]=temp;
  }
}

/*!
 * \brief Sortowanie szybkie
 *
 * Dokonuje sortowania obiektu stosujac metode sortowania szybkiego
 *
 * \param[in] &tosort Referencja do obiektu typu Iterable, ktory chcemy posortowac
 * \param[in] left Poczatek zakresu sortowania
 * \param[in] right Koniec zakresu sortowania 
 */ 
template<typename type>
void quicksort(Iterable<type> &tosort, int left, int right){
  int i=(right+left)/2;
  int j=0;
 
  if(tosort[right]<tosort[left])
    substitute(tosort[right],tosort[left]); 
  if(tosort[i] < tosort[left])
    substitute(tosort[i],tosort[left]); 
  if(tosort[right]<tosort[i])
    substitute(tosort[right],tosort[i]); 

  int piwot=tosort[i];
  i=left; j = right;
  do{
    while(tosort[i]<piwot) i++;
    while(tosort[j]>piwot) j--;
    if(i<=j){
      substitute(tosort[i],tosort[j]);
      i++; j--;
    }
  }while(i<=j);
  
  if(j>left)
    quicksort(tosort, left,j);
  if(i<right)
    quicksort(tosort, i,right);
}
#endif
