#include <iostream>
#include "base_publisher.hpp"

namespace BaseMvp {

    BaseEvent::BaseEvent(int type): eventType(type)
    {
    }

    template <class T>
    BasePresenter<T>::BasePresenter()
    {
        id_ = nextId_;
        nextId_++;
    }

    template <class T>
    int BasePresenter<T>::getId()
    {
        return id_;
    }

    template <class T>
    T *BasePresenter<T>::getModel()
    {
        return &model_;
    }

    template <class T>
    void BasePresenter<T>::registerEvent(BaseEvent event, std::function<void(BaseEvent&)> handler)
    {
        callbacks_[event.eventType] = handler;
    }

    template <class T>
    void BasePresenter<T>::addEvent(BaseEvent &event)
    {
        auto element = callbacks_.find(event.eventType);
        if (element != callbacks_.end())
        {
            element->second(event);
        }
    }

    template <class T>
    void BasePresenter<T>::subscribe(std::weak_ptr<BasePrimeSubscriber> subscriber)
    {
        subscribers_.push_back(subscriber);
    }

    template <class T>
    void BasePresenter<T>::unsubscribe(std::weak_ptr<BasePrimeSubscriber> subscriber)
    {
        subscribers_.erase(std::remove_if(subscribers_.begin(), subscribers_.end(),
            [subscriber](const auto& weak_ptr) {
                return subscriber.expired();
            }
        ), subscribers_.end());
    }

    template <class T>
    void BasePresenter<T>::notifySubscribers(BaseNotification &type)
    {
        for(const auto&ptr : subscribers_) {
            if(auto subscriber = ptr.lock()) {
                subscriber->onNotify(type);
            }
        }
    }
}
