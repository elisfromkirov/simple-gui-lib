#ifndef __WRAP_HPP__
#define __WRAP_HPP__

#include <cstdint>
#include <cassert>
#include <cstdio>

template <class R, class ...Args>
class IFunctor {
public:
    virtual ~IFunctor() {}

    virtual R operator()(Args... args) = 0; 
};

// ---------------------------------------------------------------------------------------------- //

template <class R, class ...Args>
class FunctionWrap : public IFunctor<R, Args...> {
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
FunctionWrap<R, Args...>::FunctionWrap(
    typename FunctionWrap<R, Args...>::FunctionPointer function_pointer)
        : function_pointer_(function_pointer) {}

template <class R, class ...Args>
FunctionWrap<R, Args...>::~FunctionWrap() {}

template <class R, class ...Args>
R FunctionWrap<R, Args...>::operator()(Args... args) {
    return function_pointer_(args...);
}

// ---------------------------------------------------------------------------------------------- //

template <class ...Args>
class FunctionWrap<void, Args...> : public IFunctor<void, Args...> {
public:
    typedef void (*FunctionPointer)(Args...);

public:
    FunctionWrap(FunctionPointer function_pointer);

    virtual ~FunctionWrap() override;

    virtual void operator()(Args... args) override;

private:
    FunctionPointer function_pointer_;
}; 

template <class ...Args>
FunctionWrap<void, Args...>::FunctionWrap(
    typename FunctionWrap<void, Args...>::FunctionPointer function_pointer)
        : function_pointer_(function_pointer) {}

template <class ...Args>
FunctionWrap<void, Args...>::~FunctionWrap() {}

template <class ...Args>
void FunctionWrap<void, Args...>::operator()(Args... args) {
    function_pointer_(args...);
}

// ---------------------------------------------------------------------------------------------- //

template <class T, class R, class ...Args>
class MethodWrap : public IFunctor<R, Args...> {
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
MethodWrap<T, R, Args...>::MethodWrap(
    typename MethodWrap<T, R, Args...>::ObjectPointer object_pointer, 
    typename MethodWrap<T, R, Args...>::MethodPointer method_pointer)
    : object_pointer_(object_pointer),
      method_pointer_(method_pointer) {}

template <class T, class R, class ...Args>
MethodWrap<T, R, Args...>::~MethodWrap() {}

template <class T, class R, class ...Args>
R MethodWrap<T, R, Args...>::operator()(Args... args) {
    return (object_pointer_->*method_pointer_)(args...);
}

// ---------------------------------------------------------------------------------------------- //

template <class T, class ...Args>
class MethodWrap<T, void, Args...> : public IFunctor<void, Args...> {
public:
    typedef T* ObjectPointer;
    typedef void (T::*MethodPointer)(Args...);

public:
    MethodWrap(ObjectPointer object_pointer, MethodPointer method_pointer);

    virtual ~MethodWrap() override;

    virtual void operator()(Args... args) override;

private:
    ObjectPointer object_pointer_;
    MethodPointer method_pointer_;
};

template <class T, class ...Args>
MethodWrap<T, void, Args...>::MethodWrap(
    typename MethodWrap<T, void, Args...>::ObjectPointer object_pointer, 
    typename MethodWrap<T, void, Args...>::MethodPointer method_pointer)
    : object_pointer_(object_pointer),
      method_pointer_(method_pointer) {}

template <class T, class ...Args>
MethodWrap<T, void, Args...>::~MethodWrap() {}

template <class T, class ...Args>
void MethodWrap<T, void, Args...>::operator()(Args... args) {
    (object_pointer_->*method_pointer_)(args...);
}

#endif // __WRAP_HPP__
