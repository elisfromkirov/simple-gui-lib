#ifndef __RENDER_WINDOW_HPP__
#define __RENDER_WINDOW_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

typedef sf::RenderWindow NativeWindow;
typedef sf::RenderWindow NativeRenderWindow;

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/Input.hpp"
#include "Core/Platform/IRenderTarget.hpp"

class RenderWindow : public IRenderTarget {
public:
    RenderWindow(const std::string& title, const Vector2u& size);
    virtual ~RenderWindow() override;

    virtual void Clear(const Color& color) override;

    virtual void Display() override;

    virtual NativeRenderTarget* GetNativeRenderTarget() override;

    bool IsOpen() const;
    void Close();

    NativeWindow* GetNativeWindow();

public:
    sf::RenderWindow window_;

    Vector2u         size_;
};

#endif // __RENDER_WINDOW_HPP__