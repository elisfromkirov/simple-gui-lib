#ifndef __COMMANDS_HPP__
#define __COMMANDS_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/IFilter.hpp"
#include "Application/Tools/ITool.hpp"
#include "Core/Signal/IFunctor.hpp"

class OpenEditorCommand : public IFunctor<void ()> {
public:
    OpenEditorCommand();
    virtual ~OpenEditorCommand();

    virtual void operator()() override;    
};

class SetToolCommand : public IFunctor<void ()> {
public:
    SetToolCommand(ITool* tool);
    virtual ~SetToolCommand() override;

    virtual void operator()() override; 

protected:
    ITool* tool_;
};

class SetFilterCommand : public IFunctor<void ()> {
public:
    SetFilterCommand(IFilter* filter);
    virtual ~SetFilterCommand() override;

    virtual void operator()() override; 

protected:
    IFilter* filter_;
};


#endif // __COMMANDS_HPP__