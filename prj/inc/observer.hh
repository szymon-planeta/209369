#ifndef OBSERVER_HH
#define OBSERVER_HH
#include <vector>

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
  vector <class Observer*> obss;
public:
  void notify();
};

class SaveToFile: public Observer{
public:
  void update(){
    ofstream wyniki;
    wyniki.open("wyniki.csv",ios::app);
    wyniki<<endl<<model.getN()<<","<<model.getT();
    wyniki.close();
  }
};

void Subject::notify(){
  for(int i=0; i<obss.size();i++)
    obss[i]->update();
}


#endif
