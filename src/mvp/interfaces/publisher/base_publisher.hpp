#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include "../base_pub_sub.hpp"

namespace BaseMvp {

    /*******************************************************************************
     * @brief Base event used for notifying presenter to initiate specific
     *        action. If mre flexibility is required, sub class can derive from
     *        this class and provide additional functionality. Each event should
     *        have a unique id.
     *
     ******************************************************************************/
    class BaseEvent {
        public:
            int eventType;

            BaseEvent(int type);
    };


    // TODO set it as template class to include data model.
    /*******************************************************************************
     * @brief Core functionality of presenter is to handler business logic and
     *        notify subscribers of any change in state.
     *
     ******************************************************************************/
    class BasePresenter {
        private:
            static inline int nextId_;
            int id_;
            std::map<int, std::function<void(BaseEvent&)>> callbacks_;

        protected:
            /*******************************************************************************
             * @brief Register event with handler (callback).
             *
             * @param event Event to be registered.
             * @param handler handler to be associated with event.
             *
             ******************************************************************************/
            void registerEvent(BaseEvent event, std::function<void(BaseEvent&)> handler);

        public:
            BasePresenter();

            /*******************************************************************************
             * @brief Get the Id object.
             *
             * @return int id of current instance.
             ******************************************************************************/
            int getId();

            /*******************************************************************************
             * @brief Add event to be handled. This should be called from
             *        subscriber to to notify presenter of that action  is
             *        required.
             *
             * @param event Event to be handled.
             *
             ******************************************************************************/
            void addEvent(BaseEvent &event);


    };


}