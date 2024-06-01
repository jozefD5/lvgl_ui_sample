#pragma once
#include <models/ecg_model/ecg_model.h>
#include "lvgl/lvgl.h"
#include "views/ecg_view/ecg_view.h"


namespace LvUi {

    // ECG actions/notifications enum.
    typedef enum {
        StartStopButtonPressed = 0
    } ecgEvents_t;



    /*******************************************************************************
     * @brief ECG view presenter. Handels all reruired business logic associated
     *        with ECG view and ECG data.
     ******************************************************************************/
    class EcgPresenter : public IBasePresenter {
        private:
            EcgView* view;              // View (UI)
            EcgModel* model;            // Data model for this view.

        /*******************************************************************************
         * @brief ECG LVGL demo data timer callback.
         *
         * @param timer pointer to LVGL timer.
         *
         ******************************************************************************/
        static void ecg_demo_data_timer_handler(lv_timer_t *timer);

        public:
            /*******************************************************************************
             * @brief Construct a new Ecg Presenter object
             *
             * @param view pointer to ecg view (UI) object.
             * @param EcgModel pointer to ecg mode (data) object
             *
             ******************************************************************************/
            EcgPresenter(EcgView* view, EcgModel* EcgModel);

            /*******************************************************************************
             * @brief Notify presenter stat changes of the view (UI)
             *
             * @param p pointer to notification event. Notification should include any extra
             *          data if required, such as text .
             *
             ******************************************************************************/
            void notifyPresenter(const IBaseNotificationEvent* p) override;



    };

}
