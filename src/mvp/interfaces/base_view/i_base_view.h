#pragma once

namespace LvUi {

    /*******************************************************************************
     * @brief Base presenter interface, needs to be used with every presenter.
     ******************************************************************************/
    class IBasePresenter {
        public:
            /*******************************************************************************
             * @brief Notify presenter object.
             *
             * @param selector custom type, usually enum, used to select callback based on
             *        type of event. e.g. button pressed or input text.
             * @param p pointer to object to be used as dat source for update action.

            ******************************************************************************/
            // virtual void notifyPresenter(const int selector, void* p) = 0;
            virtual void notifyPresenter(void* p) = 0;
    };


    /*******************************************************************************
     * @brief Base view interface, needs to be used with every view.
     ******************************************************************************/
    class IBaseView {
        public:
            // Presenter subscriber.
            IBasePresenter* subscriber;

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
