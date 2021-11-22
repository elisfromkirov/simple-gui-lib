#ifndef __FUNCTION_WRAP_HPP__
#define __FUNCTION_WRAP_HPP__

#include "Core/Functor/IWrap.hpp"

template <class R, class ...Args>
class FunctionWrap {};

template <class R, class ...Args>
class FunctionWrap<R(Args...)> : public IWrap<R(Args...)> {
public:
    typedef R (*FunctionPointer)(Args...);

public:
    FunctionWrap(FunctionPointer function_pointer);
    virtual ~FunctionWrap() override;

    virtual R operator()(Args... args) override;

private:
    FunctionPointer function_pointer_;
}; 

template <class R, class ...Args>
FunctionWrap<R(Args...)>::FunctionWrap(
    typename FunctionWrap<R(Args...)>::FunctionPointer function_pointer)
        : function_pointer_(function_pointer) {}

template <class R, class ...Args>
FunctionWrap<R(Args...)>::~FunctionWrap() {}

template <class R, class ...Args>
R FunctionWrap<R(Args...)>::operator()(Args... args) {
    return function_pointer_(args...);
}

#endif // __FUNCTION_WRAP_HPP__