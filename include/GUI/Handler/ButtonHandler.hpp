#ifndef __BUTTON_HANDLER_HPP__
#define __BUTTON_HANDLER_HPP__

#include <cassert>
#include <cstdint>

#include "Handler.hpp"
#include "MouseEvent.hpp"
#include "Commands.hpp"
#include "CommandQueue.hpp"

class CloseButtonHandler : public Handler {
public:
    CloseButtonHandler(Widget* widget);

    virtual ~CloseButtonHandler() override;

    virtual bool HandleEvent(const MouseButtonPressEvent* event) override;

private:
    Widget* widget_;
};

template <class Functor>
class ButtonHandler : public Handler {
public:
    template <class... Args>
    ButtonHandler(Args&&... args);

    virtual ~ButtonHandler() override;

    virtual bool HandleEvent(const MouseButtonPressEvent* event) override;

private:
    Functor functor_;
};

template <class Functor>
template <class... Args>
ButtonHandler<Functor>::ButtonHandler(Args&&... args) 
    : functor_(std::forward<Args>(args)...) {}

template <class Functor>
ButtonHandler<Functor>::~ButtonHandler() {}

template <class Functor>
bool ButtonHandler<Functor>::HandleEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    functor_();

    return true;
}

#endif // __BUTTON_HANDLER_HPP__
