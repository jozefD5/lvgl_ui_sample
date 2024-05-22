#pragma once

/*******************************************************************************
 * @brief Base view interface, needs to be used with every view.
 ******************************************************************************/
class IBaseView {
    public:
        /*******************************************************************************
         * @brief Notify presenter object.
         *
         * @param p pointer to object to be used as dat source for update action.

        ******************************************************************************/
        virtual void notifyPresenter(void* p) = 0;

};
