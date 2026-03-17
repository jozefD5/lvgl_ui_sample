#include <iostream>
#include "base_subscriber.hpp"


namespace BaseMvp {

    void BaseSubscriber::registerNotification(BaseNotification notification, std::function<void(BaseNotification&)> handler)
    {
        callbacks_[std::make_pair(notification.notificationType, notification.presenterId)] = handler;
    }

    void BaseSubscriber::onNotify(BaseNotification &notification)
    {
        auto searchResult = callbacks_
            .find(std::make_pair(notification.notificationType, notification.presenterId));

        if (searchResult != callbacks_.end())
        {
            searchResult->second(notification);
        }
    }
}
