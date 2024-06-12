#include <iostream>
#include "main_presenter.h"
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"

namespace LvUi {

    MainPresenter::MainPresenter(MainModel *dataModel) : m_dataModel_(dataModel) {
        // Setup timers.
        m_dataModel_->m_ecg_data_timer = lv_timer_create(ecg_demo_data_timer_handler, 100, this);
        m_dataModel_->m_oxygen_data_timer = lv_timer_create(oxygen_demo_data_timer_handler, 100, this);

        lv_timer_pause( m_dataModel_->m_ecg_data_timer);
        lv_timer_pause( m_dataModel_->m_oxygen_data_timer);
    }

    void MainPresenter::ecg_demo_data_timer_handler(lv_timer_t *timer)
    {
        void* data_ptr = timer->user_data;
        MainPresenter* presenter_ptr = static_cast<MainPresenter *>(data_ptr);

        // Update model.
        lv_obj_t *chart = presenter_ptr->m_dataModel_->m_ecg_chart;
        lv_chart_series_t *series = presenter_ptr->m_dataModel_->m_ecg_chart_series;

        if(chart != NULL && series != NULL) {
            lv_chart_set_next_value(chart, series, lv_rand(3, 50));
        }
    }

    void MainPresenter::oxygen_demo_data_timer_handler(lv_timer_t *timer)
    {
        void* data_ptr = timer->user_data;
        MainPresenter* presenter_ptr = static_cast<MainPresenter *>(data_ptr);

        // Update model.
        lv_obj_t *chart = presenter_ptr->m_dataModel_->m_oxygen_chart;
        lv_chart_series_t *series = presenter_ptr->m_dataModel_->m_oxygen_chart_series;

        if(chart != NULL && series != NULL) {
            lv_chart_set_next_value(chart, series, lv_rand(3, 50));
        }
    }

    void MainPresenter::setEcgDemoData(const bool enable)
    {
        if(enable) {
            std::cout << "Enabling ECG\n\r";
            lv_timer_resume(m_dataModel_->m_ecg_data_timer);
        } else {
            std::cout << "Disabling ECG\n\r";
            lv_timer_pause(m_dataModel_->m_ecg_data_timer);
        }
    }

    void MainPresenter::setOxygenDemoData(const bool enable)
    {
        if(enable) {
            std::cout << "Enabling Oxygen\n\r";
            lv_timer_resume(m_dataModel_->m_oxygen_data_timer);
        } else {
            std::cout << "Disabling Oxygen\n\r";
            lv_timer_pause(m_dataModel_->m_oxygen_data_timer);
        }
    }

    void MainPresenter::onSubscriberData(IBaseNotificationType *type)
    {
        switch (type->m_notification_type)
        {
        case 0: {
            NEcgSetSwitchState* notification_ptr = static_cast<NEcgSetSwitchState *>(type);
            setEcgDemoData(notification_ptr->m_state);
            break;
        }

        case 1: {
            NOxygenSetSwitchState* notification_ptr = static_cast<NOxygenSetSwitchState *>(type);
            setOxygenDemoData(notification_ptr->m_state);
            break;
        }

        default:
            break;
        }
    }

    void *MainPresenter::getModel(void)
    {
        return m_dataModel_;
    }
}
