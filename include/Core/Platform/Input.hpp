#ifndef __PLATFORM_HPP__
#define __PLATFORM_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/NativePlatform.hpp"

class Mouse {
public:
    Mouse();
    ~Mouse();

    void Update(const NativeEvent& event);

private:
    static MouseButton MapButton(const NativeEvent& event);

private:
    Vector2i          position_;
    MouseButton       pressed_button_;
    bool              pressed_;
};

class Keyboard {
public:
    Keyboard();
    ~Keyboard();

    void Update(const NativeEvent& event);

private:
    static Key MapKey(const NativeEvent& event);

private:
    Key               key_;
    bool              alt_;
    bool              control_;
    bool              shift_;
    bool              system_;
};

#endif // __PLATFORM_HPP__