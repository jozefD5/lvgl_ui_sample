#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>

namespace BaseMvp {

    /*******************************************************************************
     * @brief Notification event interface, represents notification
     *        subscriber can receive.
     ******************************************************************************/
    class IBaseNotificationType {
        public:
            // Notification type used to distinguished between notifications. e.g.
            // button press = 0 and button hold = 1. This should preferably be enum
            int m_notification_type;
    };

    /*******************************************************************************
     * @brief Subscriber provides core interface to subscribe to BasePublisher and
     *        received notification of any event.
     *
     ******************************************************************************/
    class BaseCoreSubscriber {
        private:
            // Map of callback functions mapped notification type key.
            std::map<int, std::function<void(const void*)>> m_callbacks_;

        public:
            /*******************************************************************************
             * @brief Set the Notification Callback object
             *
             * @param type notification, includes uniq identification integer, preferably enum.
             * @param callback callback function mapped to notification type.
             *
             ******************************************************************************/
            void setNotificationCallback(IBaseNotificationType type,
                                        std::function<void(const void*)>& callback);

            /*******************************************************************************
             * @brief Subscriber notification event receive method. Call required callback
             *        based on notification type.
             *
             * @param notification notification object which includes notification type integer.
             *
             ******************************************************************************/
            void onNotify(IBaseNotificationType *notification);
    };

    /*******************************************************************************
     * @brief Publisher allows to notify all subscribers of specific events.
     *
     ******************************************************************************/
    class BasePublisher {
        private:
            // List of subscriber.
            std::vector<std::weak_ptr<BaseCoreSubscriber>> m_subscribers_;

        public:
            /*******************************************************************************
             * @brief Add new subscriber.
             *
             * @param subscriber Subscriber to be added.
             *
             ******************************************************************************/
            void subscribe(std::weak_ptr<BaseCoreSubscriber> subscriber);

            /*******************************************************************************
             * @brief Unsubscribe from publisher.
             *
             * @param subscriber subscriber to be removed.
             *
             ******************************************************************************/
            void unsubscribe(std::weak_ptr<BaseCoreSubscriber> subscriber);

            /*******************************************************************************
             * @brief Notify all subscribers of new notification event.
             *
             * @param type notification type.
             *
             ******************************************************************************/
            void notifySubscribers(IBaseNotificationType *type);

            /*******************************************************************************
             * @brief Interface for subscriber to send data to publisher.
             *
             * @param type notification type.
             *
             ******************************************************************************/
            virtual void onSubscriberData(IBaseNotificationType *type) = 0;

            /*******************************************************************************
             * @brief Get the Model object.
             *
             * @return void* return pointer to model (data).
             ******************************************************************************/
            virtual void* getModel(void) = 0;
    };

    /*******************************************************************************
     * @brief Subscriber, in addition to core subscriber this class also includes
     *        additional functionality to support publisher/subscriber interface.
     *
     ******************************************************************************/
    class BaseSubscriber : public BaseCoreSubscriber {
        public:
            /*******************************************************************************
             * @brief Notify publisher, send notification to publisher.
             *
             * @param type Notification object.
             * @param m_publisher Publisher to be notified.
             *
             ******************************************************************************/
            void notifyPublisher(IBaseNotificationType *type, BasePublisher *m_publisher);
    };

}
