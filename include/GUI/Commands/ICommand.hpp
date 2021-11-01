#ifndef __I_COMMAND_HPP__
#define __I_COMMAND_HPP__

class ICommand {
public:
    virtual ~ICommand() {}

    virtual void Execute() = 0;
};

#endif // __I_COMMAND_HPP__
