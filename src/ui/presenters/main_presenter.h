#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"
#include "main_presenter_notifications.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Main application presenter, handles core application business logic.
     *
     ******************************************************************************/
    class MainPresenter : public IBasePublisher{
        public:
            MainModel *m_dataModel_;


        private:
            /*******************************************************************************
             * @brief Enable/disable ECG demo data.
             *
             * @param enable enable / disable flag
             *
             ******************************************************************************/
            void setEcgDemoData(const bool enable);

            /*******************************************************************************
             * @brief Enable/disable oxygen demo data.
             *
             * @param enable enable / disable flag
             *
             ******************************************************************************/
            void setOxygenDemoData(const bool enable);

            /*******************************************************************************
             * @brief ECG demo data generator.
             *
             * @param timer
             *
             ******************************************************************************/
            static void ecg_demo_data_timer_handler(lv_timer_t *timer);

            /*******************************************************************************
             * @brief Oxygen demo data generator.
             *
             * @param timer
             *
             ******************************************************************************/
            static void oxygen_demo_data_timer_handler(lv_timer_t *timer);

        public:
            /*******************************************************************************
             * @brief Construct a new Main Presenter object
             *
             * @param dataModel pointer to data model that holds presenter's data.
             *
             ******************************************************************************/
            MainPresenter(MainModel *dataModel);

            void onSubscriberData(IBaseNotificationType *type) override;

            void* getModel(void) override;
    };
}
