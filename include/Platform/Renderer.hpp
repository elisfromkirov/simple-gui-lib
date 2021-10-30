#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <cassert>
#include <cstdint>

#include "Text.hpp"
#include "Sprite.hpp"
#include "Window.hpp"

class Renderer {
public:
    Renderer(Window* window);
    ~Renderer();

    void Clear();

    void Present();

    void RenderText(Text* text, const Vector2u& position);

    void RenderSprite(Sprite* sprite, const Vector2u& position);

private:
    sf::RenderWindow* native_window_;
};

#endif // __RENDERER_HPP__
