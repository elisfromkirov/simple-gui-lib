#ifndef __CANVAS_HPP__
#define __CANVAS_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/ContainerWidget.hpp"

class Canvas : public ContainerWidget {
public:
    Canvas(const Rect2& rect);
    virtual ~Canvas();

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;
};

#endif // __CANVAS_HPP__