#ifndef OBSERVER_HH
#define OBSERVER_HH
#include <vector>
#include <fstream>
#include "stack.hh"
using namespace std;
class Subject;

class Observer{
public:
  Subject *model;

  Observer(Subject *mod){
    model=mod;
  }
  virtual void update()=0;
};

class Subject{
  Stack<Observer*> obss;
public:
  void addObs(Observer* toadd){obss.push(toadd);}
  void notify();
};

class SaveToFile: public Observer{
public:
  void update(){
    ofstream wyniki;
    wyniki.open("wyniki.csv",ios::app);
    //wyniki<<endl<<model.getCounter()<<","<<model.getTime();
    wyniki.close();
  }
};

void Subject::notify(){
  for(unsigned int i=0; i<obss.size();i++)
    obss[i]->update();
}


#endif
