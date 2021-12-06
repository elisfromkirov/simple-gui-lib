#ifndef __COMMANDS_HPP__
#define __COMMANDS_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Signal/IFunctor.hpp"

class ITool;

class SetToolCommand : public IFunctor<void ()> {
public:
    SetToolCommand(ITool* tool);
    virtual ~SetToolCommand() override;

    virtual void operator()() override; 

protected:
    ITool* tool_;
};

#endif // __COMMANDS_HPP__