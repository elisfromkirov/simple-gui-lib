#include "GUI/Config.hpp"
#include "Editor/Editor.hpp"

Editor::Editor()
    : Application{"editor"},
      main_panel_{window_.GetSize()},
      widget_manager_{&main_panel_} {
    event_manager_->RegisterListener(&widget_manager_);
}

Editor::~Editor() {}

void Editor::Run() {
    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_manager_->DispatchEvents();

        renderer_.Clear(Color(1.f, 0.f, 0.f, 1.f));

        main_panel_.OnRender(&renderer_);

        renderer_.Present();
    }
}
