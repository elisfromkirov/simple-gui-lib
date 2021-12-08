#ifndef __EDITOR_HPP__
#define __EDITOR_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Application/Events/ApplicationEvent.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/TitleBar.hpp"

class Canvas : public ContainerWidget {
public:
    Canvas(const Rect2& rect);
    virtual ~Canvas();

    virtual void OnRender(IRenderTarget* render_target) override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    bool OnApplyFilterEvent(const ApplyFilterEvent* event);
};

class Editor : public ContainerWidget {
public:
    Editor(const Rect2& rect, const std::string& name);
    virtual ~Editor() override;

protected:
    TitleBar* title_bar_;
    Canvas*   canvas_;
};

#endif // __EDITOR_HPP__