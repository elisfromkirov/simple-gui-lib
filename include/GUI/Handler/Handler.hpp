#ifndef __HANDLER_HPP__
#define __HANDLER_HPP__

class Handler {
public:
    virtual ~Handler() {}

    template <class EventT>
    bool OnEvent(const EventT* event) {
        assert(event);

        return false;
    }
};

#endif // __HANDLER_HPP__
