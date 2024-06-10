#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include "i_base_mvp.h"


namespace BaseMvp {
    /*******************************************************************************
     * @brief Notification event interface, represents notification
     *        subscriber can receive.
     ******************************************************************************/
    class IBaseNotificationType {
        public:
            // Notification type used to distinguished between notifications. e.g.
            // button press = 0 and button hold = 1. This should preferably be enum
            int notificationType;

        IBaseNotificationType(int type): notificationType(type) {}
    };

    /*******************************************************************************
     * @brief Subscriber provides interface to subscribe to IBasePublisher and
     *        received notification of any event.
     *
     ******************************************************************************/
    class IBaseSubscriber {
        private:
            // Map of callback functions mapped notification type key.
            std::map<int, std::function<void(const void*)>> m_callbacks_;

        public:
            ~IBaseSubscriber() = default;

            /*******************************************************************************
             * @brief Set the Notification Callback object
             *
             * @param type notification, includes uniq identification integer, preferably enum.
             * @param callback callback function mapped to notification type.
             *
             ******************************************************************************/
            void setNotificationCallback(IBaseNotificationType type, std::function<void(const void*)>& callback);

            /*******************************************************************************
             * @brief Subscriber notification event receive method. Call required callback
             *        based on notification type.
             *
             * @param notification notification object which includes notification type integer.
             *
             ******************************************************************************/
            void onNotify(IBaseNotificationType notification);
    };


    /*******************************************************************************
     * @brief Publisher interface, allows to notify all subscribers of specific events.
     *
     ******************************************************************************/
    class IBasePublisher {
        private:
            // List of subscriber.
            std::vector<std::shared_ptr<IBaseSubscriber>> m_subscribers_;

        public:
            ~IBasePublisher() = default;

            /*******************************************************************************
             * @brief Add new subscriber.
             *
             * @param subscriber Subscriber to be added.
             *
             ******************************************************************************/
            void subscribe(std::shared_ptr<IBaseSubscriber> subscriber);

            /*******************************************************************************
             * @brief Unsubscribe from publisher.
             *
             * @param subscriber subscriber to be removed.
             *
             ******************************************************************************/
            void unsubscribe(std::shared_ptr<IBaseSubscriber> subscriber);

            /*******************************************************************************
             * @brief Notify all subscribers of new notification event.
             *
             * @param type notification type.
             *
             ******************************************************************************/
            void notify(IBaseNotificationType type);
    };

}
