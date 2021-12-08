#include "Application/Panels/Editor.hpp"
#include "Application/Panels/EditorPanel.hpp"
#include "GUI/Styles/FilledStyle.hpp"

const Vector2u EditorPanel::kDefaultSize{800, 600};

EditorPanel::EditorPanel(const Rect2& rect)
    : LayeredWidget{rect} {
    ApplyStyle(new FilledStyle(FilledStyle::kDarkPanel));

    SetEventHandler<EditorPanel, OpenEditorEvent>(this, &EditorPanel::OnOpenEditorEvent);
}

EditorPanel::~EditorPanel() {}

void EditorPanel::InsertEditor(const std::string& name) {
    AttachInMiddle(new Editor(Rect2(kDefaultSize), name));

    Widget* temp = children_.back();
    children_.pop_back();
    children_.push_front(temp);
}

bool EditorPanel::OnOpenEditorEvent(const OpenEditorEvent* event) {
    assert(event != nullptr);

    InsertEditor("Editor");
    return true;
}
