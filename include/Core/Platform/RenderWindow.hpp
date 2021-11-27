#ifndef __RENDER_WINDOW_HPP__
#define __RENDER_WINDOW_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/NativePlatform.hpp"
#include "Core/Platform/Input.hpp"

struct Color;
class Image;
class Text;
class Rectangle;

class RenderWindow {
public:
    RenderWindow(const std::string& title, const Vector2u& size);
    ~RenderWindow();

    void Clear(const Color& color);
    void Display();

    void RenderText(const Text& text);
    void RenderImage(const Image& image);
    void RenderRectangle(const Rectangle& rectangle);

    void PumpEvents();

    bool IsOpen() const;
    void Close();

public:
    sf::RenderWindow window_;

    Mouse            mouse_;
    Keyboard         keyboard_;
};

#endif // __RENDER_WINDOW_HPP__