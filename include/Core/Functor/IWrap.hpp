#ifndef __I_WRAP_HPP__
#define __I_WRAP_HPP__

template <class R, class ...Args>
class IWrap {};

template <class R, class ...Args>
class IWrap<R(Args...)> {
public:
    virtual ~IWrap() {}

    virtual R operator()(Args... args) = 0;
};

#endif // __I_WRAP_HPP__