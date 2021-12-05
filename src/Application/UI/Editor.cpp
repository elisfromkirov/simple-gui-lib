#include "Application/UI/Editor.hpp"
#include "Core/Platform/Color.hpp"
#include "GUI/Styles/FilledStyle.hpp"

Editor::Editor(const Rect2& rect, const std::string& name)
    : ContainerWidget{rect},
      title_bar_{nullptr},
      canvas_{nullptr} {
    title_bar_ = new TitleBar(this, name);
    AttachInTop(title_bar_);

    canvas_ = new Canvas(Rect2(rect.size.x, rect.size.y - title_bar_->GetSize().y));
    canvas_->ApplyStyle(new FilledStyle(Color(1.f, 1.f, 1.f, 1.f)));
    AttachInBottom(canvas_);
}

Editor::~Editor() {}
