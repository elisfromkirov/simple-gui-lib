#include "Config.hpp"
#include "Editor/Editor.hpp"

Editor::Editor()
    : Application{"editor"},
      main_panel_{window_.GetSize()},
      widget_manager_{&main_panel_} {
    event_manager_->RegisterListener(&widget_manager_);
}

Editor::~Editor() {}

void Editor::OnRender() {
    renderer_.Clear(Color{1, 0, 0, 1});

    main_panel_.OnRender(&renderer_);

    renderer_.Present();
}
