#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "GUI/Widgets/Image.hpp"
#include "GUI/Widgets/Label.hpp"
#include "GUI/Widgets/Widget.hpp"

template <class Functor>
class Button : public Widget {
public:
    template <class... Args>
    Button(const Vector2u& size, const Vector2i& position,
          const Color& color_on_press, const Color& color_on_release, const Color& color_on_hover, 
          Args&&... args);

    template <class... Args>
    Button(const Vector2u& size, const Vector2i& position, Image* image,
          const Color& color_on_press, const Color& color_on_release, const Color& color_on_hover, 
          Args&&... args);

    template <class... Args>
    Button(const Vector2u& size, const Vector2i& position, Label* label,
          const Color& color_on_press, const Color& color_on_release, const Color& color_on_hover, 
          Args&&... args);

    virtual ~Button() override;

    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseHover(const MouseHoverEvent* event) override;

    virtual bool OnMouseLeave(const MouseLeaveEvent* event) override;

protected:
    virtual void Render(Renderer* renderer) const override;

protected:
    Color   color_on_press_;
    Color   color_on_release_;
    Color   color_on_hover_;

    Functor functor_;

    bool    pressed_;
    bool    hovered_;
};

template <class Functor>
template <class... Args>
Button<Functor>::Button(const Vector2u& size, 
                        const Vector2i& position,
                        const Color& color_on_press,
                        const Color& color_on_release,
                        const Color& color_on_hover,
                        Args&&... args)
    : Widget{size, position}, 
      color_on_press_{color_on_press},
      color_on_release_{color_on_release},
      color_on_hover_{color_on_hover},
      functor_{std::forward<Args>(args)...},
      pressed_{false},
      hovered_{false} {}

template <class Functor>
template <class... Args>
Button<Functor>::Button(const Vector2u& size, 
                        const Vector2i& position,
                        Image* image,
                        const Color& color_on_press,
                        const Color& color_on_release,
                        const Color& color_on_hover,
                        Args&&... args)
    : Widget{size, position}, 
      color_on_press_{color_on_press},
      color_on_release_{color_on_release},
      color_on_hover_{color_on_hover},
      functor_{std::forward<Args>(args)...},
      pressed_{false},
      hovered_{false} {
    assert(image != nullptr);
    assert(image->GetSize().x < size.x && image->GetSize().y < size.y);
        
    image->OnMove(Vector2i(
        position.x + static_cast<int32_t>(size.x - image->GetSize().x)/2 - image->GetPosition().x,
        position.y + static_cast<int32_t>(size.y - image->GetSize().y)/2 - image->GetPosition().y));

    Attach(image);
}

template <class Functor>
template <class... Args>
Button<Functor>::Button(const Vector2u& size, 
                        const Vector2i& position,
                        Label* label,
                        const Color& color_on_press,
                        const Color& color_on_release,
                        const Color& color_on_hover,
                        Args&&... args)
    : Widget{size, position}, 
      color_on_press_{color_on_press},
      color_on_release_{color_on_release},
      color_on_hover_{color_on_hover},
      functor_{std::forward<Args>(args)...},
      pressed_{false},
      hovered_{false} {
    assert(label != nullptr);
    assert(label->GetSize().x < size.x && label->GetSize().y < size.y);
        
    label->OnMove(Vector2i(
        position.x + static_cast<int32_t>(size.x - label->GetSize().x)/2 - label->GetPosition().x,
        position.y + static_cast<int32_t>(size.y - label->GetSize().y)/2 - label->GetPosition().y));

    Attach(label);
}

template <class Functor>
Button<Functor>::~Button() {}

template <class Functor>
bool Button<Functor>::OnMouseButtonPress(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (Contains(event->GetMousePosition())) {
        pressed_ = true;
        functor_();
        return true;
    }

    return false;
}

template <class Functor>
bool Button<Functor>::OnMouseButtonRelease(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (Contains(event->GetMousePosition())) {
        pressed_ = false;
        return true;
    }
    
    return false;
}

template <class Functor>
bool Button<Functor>::OnMouseHover(const MouseHoverEvent* event) {
    assert(event != nullptr);

    hovered_ = true;
    return true;
}

template <class Functor>
bool Button<Functor>::OnMouseLeave(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    hovered_ = false;
    return true;
}

template <class Functor>
void Button<Functor>::Render(Renderer* renderer) const {
    assert(renderer != nullptr);

    if (pressed_) {
        renderer->RenderRectangle(position_, size_, color_on_press_);
    } else {
        if (hovered_) {
            renderer->RenderRectangle(position_, size_, color_on_hover_);
        } else {
            renderer->RenderRectangle(position_, size_, color_on_release_);
        }
    }
}

#endif // __BUTTON_HPP__
