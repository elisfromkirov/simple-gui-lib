#ifndef __I_FUNCTOR_HPP__
#define __I_FUNCTOR_HPP__

template <class R, class ...Args>
class IFunctor {};

template <class R, class ...Args>
class IFunctor<R(Args...)> {
public:
    virtual ~IFunctor() {}

    virtual R operator()(Args... args) = 0;
};

#endif // __I_FUNCTOR_HPP__