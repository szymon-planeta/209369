//lista.hh
#ifndef LISTA_HH
#define LISTA_HH

#include "program.hh"

/*!
 * \file
 * \brief Definicja klasy Lista
 */

/*
struct pole{
  int wartosc;
  pole *next;
  pole(){wartosc=0; next=NULL;}
};
*/


template <class type, class type2>
class Lista: public Program{
  //zmien
  /*!
   * \brief Struktura pole
   *
   * Jest to struktura skladowa klasy Lista, zawierajaca
   * przechowywana wartosc oraz wskaznik na zmienna typu
   * pole.
   */
  struct pole{
    type val1;
    type2 val2;
    pole *next;
    pole(){next=NULL;}
};
public:  pole *first;
public:
  /*!
   * \brief Konstruktor bezparametryczny
   *
   * Ustawia poczatek listy na NULL
   */
 Lista(){
    first = NULL;
  }
  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na koniec listy.
   *
   * \param[in] x Wartosc, ktora chcemy dodac na koniec listy.
   */
  void push(type x, type2 y);

  /*!
   * \brief Metoda push
   *
   * Dodaje podana wartosc na koniec listy.
   *
   * \param[in] x Wartosc, ktora chcemy dodac na poczatek listy.
   */
  void push_front(type x, type2 y);

  /*!
   * \brief Procedura pop
   *
   * Usuwa ostatni element listy.
   */
  void pop();
  /*!
   * \brief Metoda size
   *
   * Daje informacje o rozmiarze listy (liczbie jej elementow).
   *
   * \return Rozmiar listy (liczba jej elementow)
   */
  int size();

  /*!
   * \brief Metoda wykonaj_program
   *
   * Wykonuje zadany program - dodanie zadanej ilosci danych z pliku
   * do listy za pomoca metody push()
   *
   * \retval TRUE Poprawnie wykonano program
   * \retval FALSE Nie wczytano danych
   */
  bool wykonaj_program(char* nazwa_pliku,int ilosc_danych);

  /*!
   * \brief Metoda wyczysc_dane
   *
   * Usuwa zadana ilosc elementow listy za pomoca metody pop
   *
   * \param[in] ile Liczba elementow, ktore chcemy usunac.
   */
  void wyczysc_dane(int ile);

  /*
   *!
   * \brief Metoda wyswietl
   *
   * Wyswietla wszystkie pola listy
   */
  void wyswietl(){
    if(first == NULL){
      cerr<<"Lista jest pusta!"<<endl;
    }
    else{
      pole *wsk = first;
      cout<<"Key: "<<wsk->val1<< " , Value:"<<wsk->val2<<endl;
      while(wsk->next){
	wsk=wsk->next;
	cout<<"Key: "<<wsk->val1<< " , Value:"<<wsk->val2<<endl;
      }
    }
  }

  /*
   *!
   * \brief Metoda wyswietl z argumentem key
   *
   * Wyswietla wszystkie pola, ktorych pole x ma podany klucz
   *
   * \param[in] Klucz, dla ktorego chcemy wyswietlic wszystkie pola o identycznym kluczu
   */
  void wyswietl(type key);

 /*
   *!
   * \brief Metoda daj z argumentem key
   *
   * \return Zwraca wartosc pierwszego napotkanego elementu na liscie, o kluczu rownym key
   */
  type2& daj(type key);

 /*!
   * \brief Procedura pop
   *
   * Usuwa wszystkie elementy listy o podanej wartosci val1.
   * 
   * \param[in] Wartosc val1 elementow do usuniecia
   */
  void pop(type key);
};

template <class type, class type2> void Lista<type, type2>::push(type x, type2 y){
  pole *nowe = new pole;
  nowe->val1 = x;
  nowe->val2 = y;
  if(first == NULL){
    first = nowe;
  }
  else{
    pole *wsk = first;
    while(wsk->next)
      wsk=wsk->next;
    wsk->next = nowe;
    nowe->next = NULL;
  }
}

template <class type, class type2> void Lista<type, type2>::push_front(type x, type2 y){
  pole *nowe = new pole;
  nowe->val1 = x;
  nowe->val2 = y;
  if(first == NULL){
    first = nowe;
  }
  else{
    pole *wsk = first->next;
    first->next = nowe;
    nowe->next = wsk;
  }
}

template <class type, class type2> void Lista<type, type2>::pop(){
  if(first == NULL){
    cerr<<"Lista jest pusta!"<<endl;
  }
  else{
    pole *wsk = first;
    pole *prev = NULL;
    while(wsk->next){
      prev=wsk;
      wsk=wsk->next;
    }
    if(prev==NULL){
      delete wsk;
      wsk = NULL;
    }
    else{
      prev->next = NULL;
      delete wsk;
    }
  }
}

template <class type, class type2> int Lista<type, type2>::size(){
  if(first == NULL)
    return 0;
  else{
    pole *wsk = first;
    int i=1;
    while(wsk->next){
      wsk=wsk->next;
      i++;
    }
    return i;
  }
}

template <class type, class type2> bool Lista<type, type2>::wykonaj_program(char* nazwa_pliku,int ilosc_danych){
  return true;
}

template <class type, class type2> void Lista<type, type2>::wyczysc_dane(int ile){
  for(int i=0;i<ile;i++)
    pop();
}

template<class type, class type2> void Lista<type, type2>::wyswietl(type key){
  if(first == NULL){
    cerr<<"Lista jest pusta!"<<endl;
  }
  else{
    pole *wsk = first;
    if(wsk->val1 == key)
      cout<<"Key: "<<wsk->val1<< " , Value:"<<wsk->val2<<endl;
    while(wsk->next){
      wsk=wsk->next;
      if(wsk->val1 == key)
	cout<<"Key: "<<wsk->val1<< " , Value:"<<wsk->val2<<endl;
    }
  }
}
template<class type, class type2> type2& Lista<type, type2>::daj(type key){
  if(first == NULL){
    cerr<<"Brak elementu o podanym kluczu!"<<endl;
    //type2 a;
    // return a;
  }
  else{
    pole *wsk = first;
    if(wsk->val1 == key)
      return wsk->val2;
    while(wsk->next){
      wsk=wsk->next;
      if(wsk->val1 == key)
	return wsk->val2;;
    }
  }
  //type2 a;
  //return a;
}

template<class type, class type2> void Lista<type, type2>::pop(type key){
  pole *wsk = first;
  pole *prev = NULL;
  if(first == NULL){
    cerr<<"Lista jest pusta!"<<endl;
  }
  else{
    while(wsk->val1==key){
      if(wsk->val1==key && wsk->next==NULL){
	delete wsk;
	wsk = first;
      }
      else{
	first = wsk->next;
	delete wsk;
	wsk = first;
      }
    }
  }
  while(wsk->next){
    prev=wsk;
    wsk=wsk->next;
    if(wsk->val1==key){
      prev->next=wsk->next;
      delete wsk;
      wsk=prev->next;
    }
    else{
      prev=wsk;
      wsk=wsk->next;
    }
  } 
}


#endif
