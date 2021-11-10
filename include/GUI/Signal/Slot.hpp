#ifndef __SLOT_HPP__
#define __SLOT_HPP__

#include <cstdint>
#include <cassert>

#include "GUI/Signal/Wrap.hpp"

template <class R, class ...Args>
class Slot {
private:
    static const uint64_t kBufferCapacity{32};

public:
    template <class Functor>
    Slot(const Functor& functor);

    ~Slot();

    Slot(const Slot& other) = delete;
    Slot& operator=(const Slot& other) = delete;

    R operator()(Args... args);

private:    
    IFunctor<R, Args...>* functor_;
    char                  buffer[kBufferCapacity];
};

template <class R, class ...Args>
template <class Functor>
Slot<R, Args...>::Slot(const Functor& functor) 
    : functor_{nullptr} {
    functor_ = new(buffer) Functor(functor);
}

template <class R, class ...Args>
Slot<R, Args...>::~Slot() {}

template <class R, class ...Args>
R Slot<R, Args...>::operator()(Args... args) {
    return (*functor_)(args...);
}

// ---------------------------------------------------------------------------------------------- //

template <class ...Args>
class Slot<void, Args...> {
private:
    static const uint64_t kBufferCapacity{32};

public:
    template <class Functor>
    Slot(const Functor& functor);

    ~Slot();
    
    Slot(const Slot& other) = delete;
    Slot& operator=(const Slot& other) = delete;

    void operator()(Args... args);

private:    
    IFunctor<void, Args...>* functor_;
    char                     buffer[kBufferCapacity];
};

template <class ...Args>
template <class Functor>
Slot<void, Args...>::Slot(const Functor& functor) 
    : functor_{nullptr} {
    functor_ = new(buffer) Functor(functor);
}

template <class ...Args>
Slot<void, Args...>::~Slot() {}

template <class ...Args>
void Slot<void, Args...>::operator()(Args... args) {
    (*functor_)(args...);
}

#endif // __SLOT_HPP__
