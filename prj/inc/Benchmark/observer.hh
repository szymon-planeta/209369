#ifndef OBSERVER_HH
#define OBSERVER_HH

#include <fstream>
#include "../ABData/stack.hh"
using namespace std;
class Subject;

class Observer{
public:/*
  Subject *model;

  Observer(Subject *mod){
    model=mod;
    }*/
  virtual void update(int dataNumber, double mean)=0;
};

class Subject{
protected:
  Stack<Observer*> obss;
public:
  void addObs(Observer* toadd){obss.push(toadd);}
  virtual void notify()=0;
};

class SaveToFile: public Observer{
public:
  /* SaveToFile(Benchmark *mod){
    model=mod;
    }*/
  void update(int dataNumber, double mean){
    ofstream wyniki;
    wyniki.open("wyniki.csv",ios::app);
    wyniki<<endl<<dataNumber<<","<<mean;
    wyniki.close();
  }
};

/*void Subject::notify(){
  for(unsigned int i=0; i<obss.size();i++)
    obss[i]->update();
    }*/


#endif
