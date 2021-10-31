#include "Handler.hpp"
    
Handler::~Handler() {}

bool Handler::HandleEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Handler::HandleEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Handler::HandleEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    return false;
}
