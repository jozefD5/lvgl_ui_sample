#include <iostream>
#include "base_publisher.hpp"

namespace BaseMvp {

    BaseEvent::BaseEvent(int id): eventType(id)
    {
    }


    BasePresenter::BasePresenter()
    {
        id_ = nextId_;
        nextId_++;
    }

    int BasePresenter::getId()
    {
        return id_;
    }

    void BasePresenter::registerEvent(BaseEvent &event, std::function<void(BaseEvent &)> handler)
    {
        callBacks_.insert({event.eventType, handler});
    }

    void BasePresenter::addEvent(BaseEvent &event)
    {
        auto element = callBacks_.find(event.eventType);
        if (element != callBacks_.end())
        {
            element->second(event);
        }
    }

}
