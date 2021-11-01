#include "Commands.hpp"

CloseWidgetCommand::CloseWidgetCommand(Widget* widget)
    : widget_{widget} {
    assert(widget_ != nullptr);
}

CloseWidgetCommand::~CloseWidgetCommand() {}

void CloseWidgetCommand::Execute() {
    Widget* parent = widget_->GetParent();
    
    if (parent != nullptr) {
        parent->Detach(widget_);
    }

    delete widget_;
}
