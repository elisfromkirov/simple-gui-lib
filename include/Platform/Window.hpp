#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <cassert>
#include <cstdint>
#include <SDL.h>

#include "Vector2.hpp"
#include "IRenderTarget.hpp"

class Window : public IRenderTarget {
private:
    static const Vector2<uint32_t> kDefaultPosition;
    static const Vector2<uint32_t> kDefaultSize;

public:
    Window(const char* title); 

    Window(const char* title, uint32_t x_pos, uint32_t y_pos, uint32_t width, uint32_t height);

    Window(const char* title, Vector2<uint32_t> position, Vector2<uint32_t> size);

    virtual ~Window() override;

    void* GetNativeWindow();

    virtual void* GetRenderTarget() override;

private:
    SDL_Window*       window_;

    const char*       title_;

    Vector2<uint32_t> pos_;
    Vector2<uint32_t> size_;
};

#endif // __WINDOW_HPP__
