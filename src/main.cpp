#include "Renderer.hpp"
#include "Texture.hpp"
#include "Window.hpp"

int main() {
    Window window{"test sdl wrapper"};
    
    Renderer renderer{&window};

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        renderer.SetRenderColor(Color{0.f, 0.f, 0.f});
        renderer.Clear();

        renderer.SetRenderColor(Color{1.f, 1.f, 1.f});
        renderer.RenderPoint(Vector2<uint32_t>{100, 100});
        renderer.RenderPoint(Vector2<uint32_t>{100, 200});
        renderer.RenderPoint(Vector2<uint32_t>{200, 100});
        renderer.RenderPoint(Vector2<uint32_t>{200, 200});

        renderer.Present();
    }

    return 0;
}
