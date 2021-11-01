#include "CommandQueue.hpp"

CommandQueue* CommandQueue::singleton{nullptr};

CommandQueue* CommandQueue::GetCommandQueue() {
    if (singleton == nullptr) {
        singleton = new CommandQueue();
    }

    return singleton;
}

CommandQueue::CommandQueue() {}

CommandQueue::~CommandQueue() {}

void CommandQueue::ExecuteCommands() {
    while (!queue_.empty()) {
        ICommand* command = queue_.front();
        queue_.pop_front();

        command->Execute();
    
        delete command;
    }
}

// void CommandQueue::PushCommands(ICommand* command) {
//     assert(command != nullptr);

//     queue_.push_back(command);
// }
