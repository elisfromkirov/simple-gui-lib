#include "ButtonHandler.hpp"

CloseButtonHandler::CloseButtonHandler(Widget* widget)
    : widget_{widget} {
    assert(widget_ != nullptr);
}

CloseButtonHandler::~CloseButtonHandler() {}

bool CloseButtonHandler::HandleEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    CommandQueue* command_queue = CommandQueue::GetCommandQueue();
    assert(command_queue != nullptr);

    command_queue->PushCommand<CloseWidgetCommand>(widget_);

    return true;
}
