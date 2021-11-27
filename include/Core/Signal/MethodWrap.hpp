#ifndef __METHOD_WRAP_HPP__
#define __METHOD_WRAP_HPP__

#include "Core/Functor/IFunctor.hpp"

template <class T, class R, class ...Args>
class MethodWrap {};

template <class T, class R, class ...Args>
class MethodWrap<T, R(Args...)> : public IFunctor<R(Args...)>{
public:
    typedef T* ObjectPointer;
    typedef R (T::*MethodPointer)(Args...);

public:
    MethodWrap(ObjectPointer object, MethodPointer method);
    virtual ~MethodWrap() override;

    virtual R operator()(Args... args) override;

private:
    ObjectPointer object_;
    MethodPointer method_;
};

template <class T, class R, class ...Args>
MethodWrap<T, R(Args...)>::MethodWrap(typename MethodWrap<T, R(Args...)>::ObjectPointer object, 
                                      typename MethodWrap<T, R(Args...)>::MethodPointer method)
    : object_(object),
      method_(method) {}

template <class T, class R, class ...Args>
MethodWrap<T, R(Args...)>::~MethodWrap() {}

template <class T, class R, class ...Args>
R MethodWrap<T, R(Args...)>::operator()(Args... args) {
    return (object_->*method_)(args...);
}

#endif // __METHOD_WRAP_HPP__