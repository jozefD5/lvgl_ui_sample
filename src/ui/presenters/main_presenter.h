#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Notification to set ECG switch state.
     *
     ******************************************************************************/
    class NEcgSetSwitchState : public IBaseNotificationType{
        public:
            int m_state;

        NEcgSetSwitchState(int state): m_state(state) {
            m_notification_type = 0;
        }
    };

    /*******************************************************************************
     * @brief Notification to set oxygen switch state.
     *
     ******************************************************************************/
    class NOxygenSetSwitchState : public IBaseNotificationType{
        public:
            int m_state;

        NOxygenSetSwitchState(int state): m_state(state) {
            m_notification_type = 1;
        }
    };



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
             * @brief
             *
             * @param timer
             *
             ******************************************************************************/
            static void ecg_demo_data_timer_handler(lv_timer_t *timer);

            /*******************************************************************************
             * @brief
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
