#include <iostream>
#include "base_publisher.hpp"

namespace BaseMvp {

    BaseEvent::BaseEvent(int type): eventType(type)
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

    void BasePresenter::registerEvent(BaseEvent event, std::function<void(BaseEvent&)> handler)
    {
        callbacks_[event.eventType] = handler;
    }

    void BasePresenter::addEvent(BaseEvent &event)
    {
        auto element = callbacks_.find(event.eventType);
        if (element != callbacks_.end())
        {
            element->second(event);
        }
    }

}
