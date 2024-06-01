#pragma once

namespace LvUi {

    /*******************************************************************************
     * @brief Notification event interface, represents notification view can send to
     *        presenter to notify presenter of any action.
     ******************************************************************************/
    class IBaseNotificationEvent {
        public:
            // Notification type specific to view, used by presenter to distinguishe
            // between notifications. e.g. button press = 0 and button hold = 1.
            int notificationType;

        IBaseNotificationEvent(int type): notificationType(type) {}
    };

    /*******************************************************************************
     * @brief Base presenter interface, needs to be used with every presenter.
     ******************************************************************************/
    class IBasePresenter {
        public:
            /*******************************************************************************
             * @brief Notify presenter object.
             *
             * @param p pointer to object to be used as data source for update action.
            *
            ******************************************************************************/
            virtual void notifyPresenter(const IBaseNotificationEvent* p) = 0;
    };

    /*******************************************************************************
     * @brief Base view interface, needs to be used with every view.
     ******************************************************************************/
    class IBaseView {
        public:
            // Presenter subscriber.
            IBasePresenter* subscriber;

            /*******************************************************************************
             * @brief Notify view of any change. This is used by presenter to notify view if
             *        model was updated.
             *
             * @param p pointer to object to be used as data source for update action.
             *
             ******************************************************************************/
            virtual void notifyView(const IBaseNotificationEvent* p) = 0;

            /*******************************************************************************
             * @brief Set the Subscriber object
             *
             * @param ss pointer to subscriber
             *
             ******************************************************************************/
            void setSubscriber(IBasePresenter* ss)
            {
                subscriber = ss;
            }
    };

}
