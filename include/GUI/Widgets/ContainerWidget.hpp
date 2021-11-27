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

    virtual void Resize(const Vector2u& size) override;

    virtual void Move(const Vector2i& position) override;

    virtual void OnRender(RenderTexture* texture) override;

    virtual bool OnEvent(const Event* event) override;

    bool Attach(Widget* widget);
    bool Detach(Widget* widget);    

protected:
    void RenderChildren(RenderTexture* texture);

    bool DispatchToChildren(const Event* event);

protected:
    RenderTexture      texture_;

    std::list<Widget*> children_;
};

#endif // __CONTAINER_WIDGET_HPP__