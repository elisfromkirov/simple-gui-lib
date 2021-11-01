#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <cassert>
#include <cstdint>

#include "ICommand.hpp"
#include "Widget.hpp"

class CloseWidgetCommand : public ICommand {
public:
    CloseWidgetCommand(Widget* widget);

    virtual ~CloseWidgetCommand();

    void Execute();

private:
    Widget* widget_;
};

#endif // __COMMAND_HPP__
