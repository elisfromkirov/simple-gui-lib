#ifndef __METHOD_WRAP_HPP__
#define __METHOD_WRAP_HPP__

#include "Core/Functor/IWrap.hpp"

template <class T, class R, class ...Args>
class MethodWrap {};

template <class T, class R, class ...Args>
class MethodWrap<T, R(Args...)> : public IWrap<R(Args...)>{
public:
    typedef T* ObjectPointer;
    typedef R (T::*MethodPointer)(Args...);

public:
    MethodWrap(ObjectPointer object_pointer, MethodPointer method_pointer);
    virtual ~MethodWrap() override;

    virtual R operator()(Args... args) override;

private:
    ObjectPointer object_pointer_;
    MethodPointer method_pointer_;
};

template <class T, class R, class ...Args>
MethodWrap<T, R(Args...)>::MethodWrap(
    typename MethodWrap<T, R(Args...)>::ObjectPointer object_pointer, 
    typename MethodWrap<T, R(Args...)>::MethodPointer method_pointer)
    : object_pointer_(object_pointer),
      method_pointer_(method_pointer) {}

template <class T, class R, class ...Args>
MethodWrap<T, R(Args...)>::~MethodWrap() {}

template <class T, class R, class ...Args>
R MethodWrap<T, R(Args...)>::operator()(Args... args) {
    return (object_pointer_->*method_pointer_)(args...);
}

#endif // __METHOD_WRAP_HPP__