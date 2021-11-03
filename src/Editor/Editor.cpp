#include "Editor/Editor.hpp"

Editor::Editor()
    : window_{"editor"},
      input_{&window_},
      renderer_{&window_} {}

Editor::~Editor() {}

void Editor::Run() {
    ImageWidget image("Close.bmp");

    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_manager_->DispatchEvents();

        renderer_.Clear(Color{1, 0, 0, 1});

        image.OnRender(&renderer_);

        renderer_.Present();
    }
}
