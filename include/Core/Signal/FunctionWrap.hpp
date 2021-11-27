#ifndef __FUNCTION_WRAP_HPP__
#define __FUNCTION_WRAP_HPP__

#include "Core/Signal/IFunctor.hpp"

template <class R, class ...Args>
class FunctionWrap {};

template <class R, class ...Args>
class FunctionWrap<R(Args...)> : public IFunctor<R(Args...)> {
public:
    typedef R (*FunctionPointer)(Args...);

public:
    FunctionWrap(FunctionPointer function);

    virtual ~FunctionWrap() override;

    virtual R operator()(Args... args) override;

private:
    FunctionPointer function_;
}; 

template <class R, class ...Args>
FunctionWrap<R(Args...)>::FunctionWrap(typename FunctionWrap<R(Args...)>::FunctionPointer function)
        : function_(function) {}

template <class R, class ...Args>
FunctionWrap<R(Args...)>::~FunctionWrap() {}

template <class R, class ...Args>
R FunctionWrap<R(Args...)>::operator()(Args... args) {
    return function_(args...);
}

#endif // __FUNCTION_WRAP_HPP__