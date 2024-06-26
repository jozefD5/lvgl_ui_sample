#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>

namespace BaseMvp {
    /*******************************************************************************
     * @brief Base notification used by presenter to notify subscribers of
     * any change in state.
     *
     ******************************************************************************/
    class BaseNotification {
        public:
            int presenterId;
            int notificationType;

            BaseNotification(int id , int type);
    };


    class BasePrimeSubscriber {
        public:
            std::map<std::pair<int, int>, std::function<void(BaseNotification&)>> callbacks_;

        protected:
            /*******************************************************************************
             * @brief Register notification with handler (callback).
             *
             * @param notification notification to be registered.
             * @param handler handler to be associated with notification.
             *
             ******************************************************************************/
            void registerNotification(BaseNotification notification, std::function<void(BaseNotification&)> handler);

        public:
            /*******************************************************************************
             * @brief Subscriber notification event receive method. Call required callback
             *        based on notification type. This method is called by presenter.
             *
             * @param notification notification object which includes notification type integer.
             *
             ******************************************************************************/
            void onNotify(BaseNotification &notification);
    };

}
