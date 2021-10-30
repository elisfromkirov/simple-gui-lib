#ifndef __KEY_EVENT_HPP__
#define __KEY_EVENT_HPP__

#include "IEvent.hpp"
#include "InputEventMask.hpp"

enum Key : uint32_t {
    kNoneKey,

    kKeyA,
    kKeyB,
    kKeyC,
    kKeyD,
    kKeyE,
    kKeyF,
    kKeyG,
    kKeyH,
    kKeyI,
    kKeyJ,
    kKeyK,
    kKeyL,
    kKeyM,
    kKeyN,
    kKeyO,
    kKeyP,
    kKeyQ,
    kKeyR,
    kKeyS,
    kKeyT,
    kKeyU,
    kKeyV,
    kKeyW,
    kKeyX,
    kKeyY,
    kKeyZ,

    kKey0,
    kKey1,
    kKey2,
    kKey3,
    kKey4,
    kKey5,
    kKey6,
    kKey7,
    kKey8,
    kKey9,

    kLeftArrow,
    kRightArrow,
    kUpArrow,
    kDownArrow
};

class IKeyEvent : public IEvent {
public:
    IKeyEvent(Key key, bool alt, bool control, bool shift, bool system);

    Key GetKey() const;

    bool IsAltPressed() const;

    bool IsCtrlPressed() const;

    bool IsShiftPressed() const;

    bool IsSystemPressed() const;

protected:
    Key  key_;
    bool alt_;
    bool control_;
    bool shift_;
    bool system_;
};

class KeyPressEvent : public IKeyEvent {
public:
    KeyPressEvent(Key key, bool alt, bool control, bool shift, bool system);
    virtual ~KeyPressEvent() override;

    virtual uint64_t GetCategory() const override;

    virtual uint64_t GetMask() const override;
};

class KeyReleaseEvent : public IKeyEvent {
public:
    KeyReleaseEvent(Key key, bool alt, bool control, bool shift, bool system);
    virtual ~KeyReleaseEvent() override;

    virtual uint64_t GetCategory() const override;

    virtual uint64_t GetMask() const override;
};

#endif // __KEY_EVENT_HPP__
