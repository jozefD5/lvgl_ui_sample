#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.hpp"
#include "models/main_model.hpp"
#include "main_presenter_notifications.hpp"
#include "mvp/interfaces/publisher/base_publisher.hpp"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Main application presenter, handles core application business logic.
     *
     ******************************************************************************/
    class MainPresenter : public BasePublisher{
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


typedef enum {
    TEST_EVENT_TYPE1 = 0,
    TEST_EVENT_TYPE2,
} main_app_event_t;



class TestEvent1 : public BaseMvp::BaseEvent {
    public:
        TestEvent1() : BaseEvent(TEST_EVENT_TYPE1) {}
};

class TestEvent2 : public BaseMvp::BaseEvent {
    public:
        TestEvent2() : BaseEvent(TEST_EVENT_TYPE2) {}
};





class MainAppPresenter : public BaseMvp::BasePresenter {
    private:
    void tesEvent1Callback(BaseEvent& event) {
        std::cout << "ID: " << getId() << ", TEST_EVENT_TYPE1" << std::endl;
    }

    void tesEvent2Callback(BaseEvent& event) {
        std::cout << "ID: " << getId() << ", TEST_EVENT_TYPE2" << std::endl;
    }


    public:
        MainAppPresenter() {
            std::cout << "ID: " << getId() << std::endl;

            // Register events.
            registerEvent(TestEvent1(), std::bind(&MainAppPresenter::tesEvent1Callback, this, std::placeholders::_1));
            registerEvent(TestEvent2(), std::bind(&MainAppPresenter::tesEvent2Callback, this, std::placeholders::_1));

        }
};
