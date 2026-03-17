#include <iostream>
#include "notifications.hpp"

namespace BaseMvp {
    BaseNotification::BaseNotification(int id, int type)
        : presenterId(id), notificationType(type)
    {
    }

    BaseEvent::BaseEvent(int type): eventType_(type)
    {
    }

    int BaseEvent::getType()
    {
        return eventType_;
    }

}
