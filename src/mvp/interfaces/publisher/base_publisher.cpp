#include <iostream>
#include "base_publisher.hpp"

namespace BaseMvp {

    BaseEvent::BaseEvent(int type): eventType_(type)
    {
    }

    int BaseEvent::getType()
    {
        return eventType_;
    }
}
