#include "Application/Panels/Editor.hpp"
#include "Application/Panels/EditorPanel.hpp"
#include "GUI/Styles/FilledStyle.hpp"

const Vector2u EditorPanel::kDefaultSize{800, 600};

EditorPanel::EditorPanel(const Rect2& rect)
    : LayeredWidget{rect} {
    ApplyStyle(new FilledStyle(FilledStyle::kDarkPanel));
}

EditorPanel::~EditorPanel() {}

void EditorPanel::InsertEditor(const std::string& name) {
    AttachInMiddle(new Editor(Rect2(kDefaultSize), name));
}