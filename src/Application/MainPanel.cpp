#include "MainPanel.hpp"

MainPanel::MainPanel(const Window& window)
    : Widget{window.GetSize()} {
    Attach(new RectWidget(Color{1.f, 0.f, 0.f, 1.f}, size_, position_), Vector2u());
    Attach(new Title("paint", this), Vector2u());
}

MainPanel::~MainPanel() {}

bool MainPanel::OnEvent(const IEvent* event) {
    assert(event != nullptr);

    switch (event->GetMask()) {
        case kMouseButtonPress: {
            return OnMouseButtonPress(dynamic_cast<const MouseButtonPressEvent*>(event));
        }
        case kMouseButtonRelease: {
            return OnMouseButtonRelease(dynamic_cast<const MouseButtonReleaseEvent*>(event));
        }
        case kMouseMove: {
            return OnMouseMove(dynamic_cast<const MouseMoveEvent*>(event));
        }
        default: {}
    }

    return true;
}
