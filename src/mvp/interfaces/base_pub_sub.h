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
     * @brief Subscriber provides interface to subscribe to IBasePublisher and
     *        received notification of any event.
     *
     ******************************************************************************/
    class IBaseCoreSubscriber {
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
            void setNotificationCallback(IBaseNotificationType type, std::function<void(const void*)>& callback);

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
     * @brief Publisher interface, allows to notify all subscribers of specific events.
     *
     ******************************************************************************/
    class IBasePublisher {
        private:
            // List of subscriber.
            std::vector<std::weak_ptr<IBaseCoreSubscriber>> m_subscribers_;

        public:
            /*******************************************************************************
             * @brief Add new subscriber.
             *
             * @param subscriber Subscriber to be added.
             *
             ******************************************************************************/
            void subscribe(std::weak_ptr<IBaseCoreSubscriber> subscriber);

            /*******************************************************************************
             * @brief Unsubscribe from publisher.
             *
             * @param subscriber subscriber to be removed.
             *
             ******************************************************************************/
            void unsubscribe(std::weak_ptr<IBaseCoreSubscriber> subscriber);

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
     *        poiser to publisher for bi-directional communication.
     *
     ******************************************************************************/
    class IBaseSubscriber : public IBaseCoreSubscriber {
        public:
            // Pointer to publisher, used for bi-depiction communication.
            IBasePublisher *m_publisher;

        public:
            void notifyPublisher(IBaseNotificationType *type) {
                m_publisher->onSubscriberData(type);
            }
    };


    /*******************************************************************************
     * @brief Base Presenter template class.
     *
     ******************************************************************************/
    template <class T>
    class BasePresenter : public IBasePublisher {
        public:
            // Data model.
            T *m_dataModel_;

            /*******************************************************************************
             * @brief Get the Model object.
             *
             * @return T* pointer to model data object.
             ******************************************************************************/
            T* getModel(void) {
                return m_dataModel_;
            }
    };

}
