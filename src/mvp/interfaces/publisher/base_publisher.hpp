#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include "../subscriber/base_subscriber.hpp"
#include "../notifications/notifications.hpp"

namespace BaseMvp {

    /*******************************************************************************
     * @brief Core functionality of publisher is to handler business logic and
     *        notify subscribers of any change in state.
     *
     ******************************************************************************/
    template <class T>
    class BasePublisher {
        private:
            static inline int nextId_;
            int id_;
            std::map<int, std::function<void(const void *data)>> callbacks_;
            std::vector<std::weak_ptr<BaseSubscriber>> subscribers_;
            T model_;

        protected:
            /*******************************************************************************
             * @brief Register event with handler (callback).
             *
             * @param event Event to be registered.
             * @param handler handler to be associated with event.
             *
             ******************************************************************************/
            void registerEvent(BaseEvent event, std::function<void(const void *data)> handler) {
                callbacks_[event.getType()] = handler;
            }

        public:
            BasePublisher() {
                id_ = nextId_;
                nextId_++;
            }

            /*******************************************************************************
             * @brief Get the Id object.
             *
             * @return int id of current instance.
             ******************************************************************************/
            int getId() {
                return id_;
            }

            /*******************************************************************************
             * @brief Get the Model object
             *
             * @return T pointer to object of type T.
             ******************************************************************************/
            T* getModel() {
                return &model_;
            }

            /*******************************************************************************
             * @brief Add event to be handled. This should be called from
             *        subscriber to to notify publisher of that action  is
             *        required.
             *        To add callback/handler, use std::bind. This allows you
             *        to specify function to bi bind , object to be bind to
             *        and arguments.
             *
             * @param event Event to be handled.
             * @param data data to be passed to event (callback/handler). If
             *             no data are passed, set to null.
             *
             ******************************************************************************/
            void addEvent(BaseEvent &event, const void *data) {
                auto element = callbacks_.find(event.getType());
                if (element != callbacks_.end())
                {
                    element->second(data);
                }
            }

            /*******************************************************************************
             * @brief Add new subscriber.
             *
             * @param subscriber Subscriber to be added.
             *
             ******************************************************************************/
            void subscribe(std::weak_ptr<BaseSubscriber> subscriber) {
                subscribers_.push_back(subscriber);
            }

            /*******************************************************************************
             * @brief Unsubscribe from publisher.
             *
             * @param subscriber subscriber to be removed.
             *
             ******************************************************************************/
            void unsubscribe(std::weak_ptr<BaseSubscriber> subscriber) {
                subscribers_.erase(std::remove_if(subscribers_.begin(), subscribers_.end(),
                    [subscriber](const auto& weak_ptr) {
                        return subscriber.expired();
                    }
                ), subscribers_.end());
            }

            /*******************************************************************************
             * @brief Notify all subscribers of new notification event.
             *
             * @param type notification type.
             *
             ******************************************************************************/
            void notifySubscribers(BaseNotification &type) {
                for(const auto&ptr : subscribers_) {
                    if(auto subscriber = ptr.lock()) {
                        subscriber->onNotify(type);
                    }
                }
            }

    };

}
