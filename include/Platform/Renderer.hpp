#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <cassert>
#include <cstdint>

#include "Platform/Color.hpp"
#include "Platform/Text.hpp"
#include "Platform/Sprite.hpp"
#include "Platform/Window.hpp"

class Renderer {
public:
    Renderer(Window* window);
    ~Renderer();

    void Clear(const Color& color = Color());

    void Present();

    void RenderText(const Text* text);

    void RenderSprite(const Sprite* sprite);

    void RenderRectangle(const Vector2u& position, const Vector2u& size, const Color& color);

private:
    sf::RenderWindow* native_window_;
};

#endif // __RENDERER_HPP__
