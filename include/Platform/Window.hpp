#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Platform/Platform.hpp"

class Window {
private:
    static const Vector2u kDefaultSize;

public:
    Window(const char* title);

    Window(const char* title, const Vector2u& size, const Vector2i& position);

    ~Window();

    bool IsOpen() const;
    void Close();

    NativeWindow* GetNativeWindow();

    const Vector2u& GetSize() const;

public:
    sf::RenderWindow native_window_;

    const char*      title_;
    Vector2u         size_;
    Vector2i         position_;
};

#endif // __WINDOW_HPP__
