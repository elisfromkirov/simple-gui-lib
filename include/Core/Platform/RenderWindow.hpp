#ifndef __RENDER_WINDOW_HPP__
#define __RENDER_WINDOW_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/NativePlatform.hpp"
#include "Core/Platform/Input.hpp"
#include "Core/Platform/IRenderTarget.hpp"

class RenderWindow : public IRenderTarget {
public:
    RenderWindow(const std::string& title, const Vector2u& size);
    ~RenderWindow();

    virtual void Clear(const Color& color = Color()) override;
    virtual void Display() override;

    virtual void RenderText(const Text& text) override;
    virtual void RenderImage(const Image& image) override;
    virtual void RenderRectangle(const Rectangle& rectangle) override;

    void PumpEvents();

    bool IsOpen() const;
    void Close();

public:
    sf::RenderWindow window_;

    Mouse            mouse_;
    Keyboard         keyboard_;
};

#endif // __RENDER_WINDOW_HPP__