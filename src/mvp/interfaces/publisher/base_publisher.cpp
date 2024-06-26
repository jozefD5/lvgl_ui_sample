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

    void BasePresenter::subscribe(std::weak_ptr<BasePrimeSubscriber> subscriber)
    {
        subscribers_.push_back(subscriber);
    }

    void BasePresenter::unsubscribe(std::weak_ptr<BasePrimeSubscriber> subscriber)
    {
        subscribers_.erase(std::remove_if(subscribers_.begin(), subscribers_.end(),
            [subscriber](const auto& weak_ptr) {
                return subscriber.expired();
            }
        ), subscribers_.end());
    }

    void BasePresenter::notifySubscribers(BaseNotification &type)
    {
        for(const auto&ptr : subscribers_) {
            if(auto subscriber = ptr.lock()) {
                subscriber->onNotify(type);
            }
        }
    }
}
