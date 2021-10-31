#ifndef __BUTTON_HANDLER_HPP__
#define __BUTTON_HANDLER_HPP__

#include <cassert>
#include <cstdint>

#include "Handler.hpp"
#include "MouseEvent.hpp"

template <class Functor>
class ButtonHandler : public Handler {
public:
    template <class... Args>
    ButtonHandler(Args&&... args);

    virtual ~ButtonHandler() override;

    bool OnEvent(const MouseButtonPressEvent* event);

private:
    Functor functor_;
};

template <class Functor>
template <class... Args>
ButtonHandler<Functor>::ButtonHandler(Args&&... args) 
    : Functor{std::forward<Args>(args)...} {}

template <class Functor>
ButtonHandler<Functor>::~ButtonHandler() {}

template <class Functor>
bool ButtonHandler<Functor>::OnEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    functor_();

    return true;
}

#endif // __BUTTON_HANDLER_HPP__
