#include "Core/EventManager/Event.hpp"

Event::Event(uint64_t type)
    : type_{type} {}

Event::~Event() {}

uint64_t Event::GetType() const {
    return type_;
}
