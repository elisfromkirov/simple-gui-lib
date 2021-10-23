#include "QuitEvent.hpp"

QuitEvent::QuitEvent() {}

QuitEvent::~QuitEvent() {}

uint64_t QuitEvent::GetMask() const {
    return kQuitEventMask;
}
