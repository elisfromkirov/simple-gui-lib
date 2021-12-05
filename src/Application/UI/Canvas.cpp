#include "Application/UI/Canvas.hpp"
#include "Application/Tools/ITool.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"

Canvas::Canvas(const Rect2& rect) 
    : ContainerWidget{rect} {}

Canvas::~Canvas() {}

bool Canvas::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    ITool* tool = ToolManager::GetInstance()->GetActiveTool();
    if (tool != nullptr) {
        Vector2i position = event->GetMousePosition() - rect_.position;

        tool->BeginDraw(texture_, position);
    }

    return true;
}

bool Canvas::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    ITool* tool = ToolManager::GetInstance()->GetActiveTool();
    if (tool != nullptr) {
        Vector2i position = event->GetMousePosition() - rect_.position;

        tool->EndDraw(texture_, position);
    }

    return true;
}

bool Canvas::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (!(HitTest(event->GetMousePosition()) && HitTest(event->GetOldMousePosition()))) {
        return false;
    }

    if (!event->IsButtonPressed()) {
        return true;
    }

    ITool* tool = ToolManager::GetInstance()->GetActiveTool();
    if (tool != nullptr) {
        Vector2i position     = event->GetMousePosition() - rect_.position;
        Vector2i old_position = event->GetOldMousePosition() - rect_.position;

        tool->Draw(texture_, position, old_position);
    }

    return true;
}