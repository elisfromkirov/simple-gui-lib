#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <cassert>
#include <cstdint>
#include <SDL.h>

#include "Vector2.hpp"

class Window {
private:
    static const Vector2<uint32_t> kDefaultPosition;
    static const Vector2<uint32_t> kDefaultSize;

public:
    Window(const char* title);

    Window(const char* title, Vector2<uint32_t> position, Vector2<uint32_t> size);

    ~Window();

    void* GetNativeWindow();

private:
    SDL_Window*       window_;

    const char*       title_;

    Vector2<uint32_t> position_;
    Vector2<uint32_t> size_;
};

#endif // __WINDOW_HPP__
