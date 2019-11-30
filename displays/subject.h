#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"

template <typename Infotype> class Subject {
  std::vector<Observer<Infotype>*> observers;
 public:
  void attach(Observer<Infotype> *o);  
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
};

template <typename Infotype>
void Subject<Infotype>::attach(Observer<Infotype> *o) {
  observers.emplace_back(o);
}

template <typename Infotype>
void Subject<Infotype>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

#endif
