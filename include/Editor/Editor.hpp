#ifndef __EDITOR_HPP__
#define __EDITOR_HPP__

#include "Core/Application/Application.hpp"
#include "GUI/Widgets/ImageWidget.hpp"
#include "Platform/Input.hpp"
#include "Platform/Renderer.hpp"
#include "Platform/Window.hpp"

class Editor : public Application {
public:
    Editor();
    ~Editor();

    void Run();

private:
    Window   window_;
    Input    input_;
    Renderer renderer_;
};

#endif // __EDITOR_HPP__
