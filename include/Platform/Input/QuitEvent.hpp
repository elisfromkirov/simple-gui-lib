#ifndef __PLATROFM_EVENT_HPP__
#define __PLATROFM_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "IEvent.hpp"

class QuitEvent : public IEvent {
public:
    QuitEvent();
    virtual ~QuitEvent() override;

    virtual uint64_t GetMask() const override;
};

#endif // __PLATROFM_EVENT_HPP__
