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
             * @param p pointer to object to be used as dat source for update action.

            ******************************************************************************/
            // TODO, use templeate instead of void pointer.
            virtual void notifyPresenter(void* p) = 0;
    };


    /*******************************************************************************
     * @brief Base view interface, needs to be used with every view.
     ******************************************************************************/
    class IBaseView {
        public:
            // Presenter subscriber.
            IBasePresenter* subscriber;

            void setSubscriber(IBasePresenter* ss) {
                subscriber = ss;
            }
    };
}
