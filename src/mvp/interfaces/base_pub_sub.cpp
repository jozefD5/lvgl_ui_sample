#include<iostream>
#include <map>
#include <functional>
#include <memory>
#include "base_pub_sub.hpp"

namespace BaseMvp {

    void BaseCoreSubscriber::setNotificationCallback(
        IBaseNotificationType type,
        std::function<void(const void*)>& callback) {

        m_callbacks_.insert({type.m_notification_type, callback});
    }

    void BaseCoreSubscriber::onNotify(IBaseNotificationType *notification)
    {
        auto element = m_callbacks_.find(notification->m_notification_type);
        if(element != m_callbacks_.end()) {
            element->second(&notification);
        }
    }

    void BaseSubscriber::notifyPublisher(IBaseNotificationType *type,
                                         BasePublisher *m_publisher)
    {
        m_publisher->onSubscriberData(type);
    }

    void BasePublisher::subscribe(std::weak_ptr<BaseCoreSubscriber> subscriber)
    {
        m_subscribers_.push_back(subscriber);
    }

    void BasePublisher::unsubscribe(std::weak_ptr<BaseCoreSubscriber> subscriber)
    {
        m_subscribers_.erase(std::remove_if(
            m_subscribers_.begin(), m_subscribers_.end(),
            [subscriber](const auto& weak_ptr) {
                return subscriber.expired();
            }), m_subscribers_.end());
    }

    void BasePublisher::notifySubscribers(IBaseNotificationType *type)
    {
        for(const auto&ptr : m_subscribers_) {
            if(auto subscriber = ptr.lock()) {
                subscriber->onNotify(type);
            }
        }
    }
}
