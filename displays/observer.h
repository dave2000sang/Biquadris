#ifndef _OBSERVER_H_
#define _OBSERVER_H_

template <typename Infotype> class Subject;

template <typename Infotype> class Observer {
 public:
  virtual void notify(Subject<Infotype> &whoFrom) = 0; // pass the Subject that called the notify method
  virtual ~Observer() = default;
};
#endif
