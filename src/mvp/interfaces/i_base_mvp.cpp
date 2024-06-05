#include<iostream>
#include <map>
#include <functional>
#include <memory>
#include "base_pub_sub.h"

namespace BaseMvp {

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

    void BaseMvp::IBasePublisher::subscribe(IBaseSubscriber *subscriber)
    {
        m_subscribers_.push_back(std::weak_ptr<IBaseSubscriber>(subscriber));
    }

}
