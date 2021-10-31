#ifndef __HANDLER_HPP__
#define __HANDLER_HPP__

#include <cassert>
#include <cstdint>

#include "MouseEvent.hpp"

class Handler {
public:
    virtual ~Handler();

    virtual bool HandleEvent(const MouseButtonPressEvent* event);
    virtual bool HandleEvent(const MouseButtonReleaseEvent* event);
    virtual bool HandleEvent(const MouseMoveEvent* event);
};

#endif // __HANDLER_HPP__
