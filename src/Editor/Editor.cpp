#include "Editor/Editor.hpp"

Editor::Editor()
    : window_{"editor"},
      input_{&window_},
      renderer_{&window_} {}

Editor::~Editor() {}

void Editor::Run() {
    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_manager_->DispatchEvents();

        renderer_.Clear();

        renderer_.Present();
    }
}
