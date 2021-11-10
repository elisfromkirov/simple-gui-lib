#ifndef __SIGNAL_HPP__
#define __SIGNAL_HPP__

#include <cstdint>
#include <cassert>
#include <list>

#include "GUI/Signal/Slot.hpp"
#include "GUI/Signal/Wrap.hpp"

template <class R, class ...Args>
class Signal {
public:
    R operator()(Args... args);

    template <class T>
    void Connect(typename MethodWrap<T, R, Args...>::ObjectPointer object_pointer,
                 typename MethodWrap<T, R, Args...>::MethodPointer method_pointer);

    void Connect(typename FunctionWrap<R, Args...>::FunctionPointer function_pointer);

private:
    std::list<Slot<R, Args...>> slots_;
};

template <class R, class ...Args>
R Signal<R, Args...>::operator()(Args... args) {
    for (auto iter = slots_.begin(); iter != slots_.end(); ++iter) {
        (*iter)(args...);
    }
}

template <class R, class ...Args>
template <class T>
void Signal<R, Args...>::Connect(
    typename MethodWrap<T, R, Args...>::ObjectPointer object_pointer,
    typename MethodWrap<T, R, Args...>::MethodPointer method_pointer) {
    slots_.push_back(Slot<R, Args...>(MethodWrap<T, R, Args...>(object_pointer, method_pointer)));
}

template <class R, class ...Args>
void  Signal<R, Args...>::Connect(
    typename FunctionWrap<R, Args...>::FunctionPointer function_pointer) {
    slots_.push_back(Slot<R, Args...>(FunctionWrap<R, Args...>(function_pointer)));
}

// ----------------------------------------------------------------------------------------------

template <class ...Args>
class Signal<void, Args...> {
public:
    void operator()(Args... args);

    template <class T>
    void Connect(typename MethodWrap<T, void, Args...>::ObjectPointer object_pointer,
                 typename MethodWrap<T, void, Args...>::MethodPointer method_pointer);

    void Connect(typename FunctionWrap<void, Args...>::FunctionPointer function_pointer);

private:
    std::list<Slot<void, Args...>> slots_;
};

template <class ...Args>
void Signal<void, Args...>::operator()(Args... args) {
    for (auto iter = slots_.begin(); iter != slots_.end(); ++iter) {
        (*iter)(args...);
    }
}

template <class ...Args>
template <class T>
void Signal<void, Args...>::Connect(
    typename MethodWrap<T, void, Args...>::ObjectPointer object_pointer,
    typename MethodWrap<T, void, Args...>::MethodPointer method_pointer) {
    slots_.emplace_back(MethodWrap<T, void, Args...>(object_pointer, method_pointer));
}

template <class ...Args>
void  Signal<void, Args...>::Connect(
    typename FunctionWrap<void, Args...>::FunctionPointer function_pointer) {
    slots_.emplace_back(FunctionWrap<void, Args...>(function_pointer));
}

#endif // __SIGNAL_HPP__
