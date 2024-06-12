#include<iostream>
#include <map>
#include <functional>
#include <memory>
#include "base_pub_sub.h"

namespace BaseMvp {

    // Subscriber.
    void IBaseCoreSubscriber::setNotificationCallback(IBaseNotificationType type, std::function<void(const void*)>& callback) {
        m_callbacks_.insert({type.m_notification_type, callback});
    }

    void IBaseCoreSubscriber::onNotify(IBaseNotificationType *notification)
    {
        auto element = m_callbacks_.find(notification->m_notification_type);
        if(element != m_callbacks_.end()) {
            element->second(&notification);
        }
    }


    // Publisher.
    void IBasePublisher::subscribe(std::weak_ptr<IBaseCoreSubscriber> subscriber)
    {
        m_subscribers_.push_back(subscriber);
    }

    // TODO, implement.
    void IBasePublisher::unsubscribe(std::weak_ptr<IBaseCoreSubscriber> subscriber)
    {
        // auto iter =
        // if(iter != m_subscribers_.end()) {
        //     m_subscribers_.erase(iter);
        // }
    }

    void IBasePublisher::notifySubscribers(IBaseNotificationType *type)
    {
        for(const auto&ptr : m_subscribers_) {
            if(auto subscriber = ptr.lock()) {
                subscriber->onNotify(type);
            }
        }
    }
}
