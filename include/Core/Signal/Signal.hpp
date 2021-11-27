#ifndef __SIGNAL_HPP__
#define __SIGNAL_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/Signal/Slot.hpp"

template <class R, class ...Args>
class Signal {};

template <class R, class ...Args>
class Signal<R(Args...)> {
public:
    R operator()(Args... args);

    void Connect(IFunctor<R(Args...)>* functor);

    void Connect(typename FunctionWrap<R(Args...)>::FunctionPointer function);

    template <class T>
    void Connect(typename MethodWrap<T, R(Args...)>::ObjectPointer object,
                 typename MethodWrap<T, R(Args...)>::MethodPointer method);

private:
    std::list<Slot<R(Args...)>> slots_;
};

template <class R, class ...Args>
R Signal<R(Args...)>::operator()(Args... args) {
    for (auto iter = slots_.begin(); iter != slots_.end(); ++iter) {
        (*iter)(args...);
    }
}

template <class R, class ...Args>
void Signal<R(Args...)>::Connect(IFunctor<R(Args...)>* functor) {
    slots_.emplace_back(functor);
}

template <class R, class ...Args>
void  Signal<R(Args...)>::Connect(typename FunctionWrap<R(Args...)>::FunctionPointer function) {
    slots_.emplace_back(new FunctionWrap<R(Args...)>(function));
}

template <class R, class ...Args>
template <class T>
void Signal<R(Args...)>::Connect(typename MethodWrap<T, R(Args...)>::ObjectPointer object,
                                 typename MethodWrap<T, R(Args...)>::MethodPointer method) {
    slots_.emplace_back(new MethodWrap<T, R(Args...)>(object, method));
}

#endif // __SIGNAL_HPP__