#ifndef __SLOT_HPP__
#define __SLOT_HPP__

#include "Core/Functor/FunctionWrap.hpp"
#include "Core/Functor/MethodWrap.hpp"

template <class R, class ...Args>
class Slot {};

template <class R, class ...Args>
class Slot<R(Args...)> {
public:
    Slot(IFunctor<R(Args...)>* wrap);
    ~Slot();

    R operator()(Args... args); 

private:
    IFunctor<R(Args...)>* wrap_;
};

template <class R, class ...Args>
Slot<R(Args...)>::Slot(IFunctor<R(Args...)>* wrap)
    : wrap_{wrap} {}

template <class R, class ...Args>
Slot<R(Args...)>::~Slot() {
    delete wrap_;
}

template <class R, class ...Args>
R Slot<R(Args...)>::operator()(Args... args) {
    return (*wrap_)(args...);
}

#endif // __SLOT_HPP__