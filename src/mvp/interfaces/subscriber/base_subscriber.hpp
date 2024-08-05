#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include "../notifications/notifications.hpp"

namespace BaseMvp {

    /*******************************************************************************
     * @brief Base subscriber allows to subscriber to subscriber to presenter
     *        to receive notifications of any state changes. It also allows
     *        to to send events to presenter (request action).
     *
     ******************************************************************************/
    class BaseSubscriber {
        public:
            std::map<std::pair<int, int>, std::function<void(BaseNotification&)>> callbacks_;

        public:
            /*******************************************************************************
             * @brief Subscriber notification event receive method. Call required callback
             *        based on notification type. This method is called by presenter.
             *
             * @param notification notification object which includes notification type integer.
             *
             ******************************************************************************/
            void onNotify(BaseNotification &notification);

        protected:
            /*******************************************************************************
             * @brief Register notification with handler (callback).
             *
             * @param notification notification to be registered.
             * @param handler handler to be associated with notification.
             *
             ******************************************************************************/
            void registerNotification(BaseNotification notification, std::function<void(BaseNotification&)> handler);
    };
}
