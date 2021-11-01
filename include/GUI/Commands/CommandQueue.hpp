#ifndef __COMMAND_QUEUE_HPP__
#define __COMMAND_QUEUE_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "ICommand.hpp"

class CommandQueue {
public:
    ~CommandQueue();

    void ExecuteCommands();

    template <class CommandT, class... Args>
    void PushCommand(Args&&... args);

    static CommandQueue* GetCommandQueue();

private:
    CommandQueue();
    
    static CommandQueue* singleton;
    
private:
    std::list<ICommand*> queue_;
};

template <class CommandT, class... Args>
void CommandQueue::PushCommand(Args&&... args) {
    CommandT* event = new CommandT(std::forward<Args>(args)...);

    queue_.push_back(event);
}

#endif // __COMMAND_QUEUE_HPP__
