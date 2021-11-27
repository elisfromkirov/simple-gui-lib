#ifndef __CONTAINER_WIDGET_HPP__
#define __CONTAINER_WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "GUI/Widgets/Widget.hpp"

class ContainerWidget : public Widget {
public:
    ContainerWidget(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~ContainerWidget();

    virtual bool OnEvent(const Event* event) override;

    virtual void Resize(const Vector2u& size) override;

    virtual void Move(const Vector2i& position) override;

    virtual void OnRender() override;

    bool Attach(Widget* widget);
    bool Detach(Widget* widget);

protected:
    bool DispatchToChildren(const Event* event);

protected:
    void RenderChildren();

    std::list<Widget*> children_;
};

#endif // __CONTAINER_WIDGET_HPP__