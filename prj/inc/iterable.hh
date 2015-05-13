#ifndef ITERABLE_HH
#define ITERABLE_HH 

template <class type>
class Iterable{
public:
  virtual type& operator [](const unsigned int index)=0;
};

#endif
