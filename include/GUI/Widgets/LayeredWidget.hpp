#ifndef __LAYERED_CONTAINER_WIDGET_HPP__
#define __LAYERED_CONTAINER_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/ContainerWidget.hpp"

class LayeredWidget : public ContainerWidget {
public:
    LayeredWidget(const Rect2& rect);
    virtual ~LayeredWidget() override;

    bool FilterMouseButtonPressEvent(const MouseButtonPressEvent* event);
};

#endif // __LAYERED_CONTAINER_WIDGET_HPP__