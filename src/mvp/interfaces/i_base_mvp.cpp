#include<iostream>
#include <map>
#include <functional>
#include <memory>
#include "base_pub_sub.h"

namespace BaseMvp {

    // Subscriber.
    void IBaseSubscriber::setNotificationCallback(IBaseNotificationType type, std::function<void(const void*)>& callback) {
        m_callbacks_.insert({type.notificationType, callback});
    }

    void IBaseSubscriber::onNotify(IBaseNotificationType notification)
    {
        auto element = m_callbacks_.find(notification.notificationType);
        if(element != m_callbacks_.end()) {
            element->second(&notification);
        }
    }


    // Publisher.
    void IBasePublisher::subscribe(std::shared_ptr<IBaseSubscriber> subscriber)
    {
        m_subscribers_.push_back(subscriber);
    }

    void IBasePublisher::unsubscribe(std::shared_ptr<IBaseSubscriber> subscriber)
    {
        // TODO, implement.

        // auto iter =
        // if(iter != m_subscribers_.end()) {
        //     m_subscribers_.erase(iter);
        // }
    }

    void IBasePublisher::notify(IBaseNotificationType type)
    {
        for(const auto&ptr : m_subscribers_) {
            ptr->onNotify(type);
        }
    }

}
