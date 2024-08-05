#pragma once
#include <iostream>


namespace BaseMvp {

    /// @brief Base notification used by presenter to notify subscribers of
    ///        any change. Presenters sends notification to subscribers to
    ///        alert of specific change in state.
    class BaseNotification {
        public:
            int presenterId;
            int notificationType;

        public:
            BaseNotification(int id , int type);
    };

    /// @brief Base event used for notifying presenter to initiate specific
    ///        action. Subscriber sends event to presenter to initiate action.
    ///        If more flexibility is required, sub class can derive from
    ///        this class and provide additional functionality. Each event should
    ///        have a unique id.
    class BaseEvent {
        public:
            BaseEvent(int type);

            int getType();

        private:
            int eventType_;
    };

}
