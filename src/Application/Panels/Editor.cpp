#include "Application/Tools/ITool.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "Application/Panels/Editor.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/FilledStyle.hpp"

Canvas::Canvas(const Rect2& rect) 
    : ContainerWidget{rect} {
    texture_->Clear(Color(1.f, 1.f, 1.f, 1.f));
    texture_->Display();

    SetEventHandler<Canvas, ApplyFilterEvent>(this, &Canvas::OnApplyFilterEvent);
}

Canvas::~Canvas() {}

void Canvas::OnRender(IRenderTarget* render_target) {
    assert(render_target != nullptr);

    render_target->RenderImage(Image(texture_, MapPositionToParent()));
}

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

bool Canvas::OnApplyFilterEvent(const ApplyFilterEvent* event) {
    assert(event != nullptr);

    IFilter* filter = event->GetFilter();
    filter->Apply(texture_);

    return true;
}

Editor::Editor(const Rect2& rect, const std::string& name)
    : ContainerWidget{rect},
      title_bar_{nullptr},
      canvas_{nullptr} {
    title_bar_ = new TitleBar(this, name);
    canvas_    = new Canvas(Rect2(rect.size.x, rect.size.y - title_bar_->GetSize().y));

    AttachInTop(title_bar_);
    AttachInBottom(canvas_);
}

Editor::~Editor() {}