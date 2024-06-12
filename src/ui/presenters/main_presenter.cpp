#include <iostream>
#include "main_presenter.h"
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"

namespace LvUi {

    MainPresenter::MainPresenter(MainModel *dataModel) : m_dataModel_(dataModel) {
        // Setup ECG timer.
        m_dataModel_->m_ecg_data_timer = lv_timer_create(ecg_demo_data_timer_handler, 100, this);
        lv_timer_pause( m_dataModel_->m_ecg_data_timer);
    }


    // ECG demo data timer handler, generates demo data as set time interval.
    void MainPresenter::ecg_demo_data_timer_handler(lv_timer_t *timer)
    {
        void* data_ptr = timer->user_data;
        MainPresenter* presenter_ptr = static_cast<MainPresenter *>(data_ptr);

        // Update model.
        lv_obj_t *chart = presenter_ptr->m_dataModel_->m_ecg_chart;
        lv_chart_series_t *series = presenter_ptr->m_dataModel_->m_ecg_chart_series;

        if(chart != NULL && series != NULL) {
            std::cout << "ECG demo running ...\n\r";
            lv_chart_set_next_value(chart, series, lv_rand(3, 50));
        }


        // Notify view.
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

    void MainPresenter::onSubscriberData(IBaseNotificationType *type)
    {
        switch (type->m_notification_type)
        {
        case 0: {
            NEcgSetSwitchState* notification_ptr = static_cast<NEcgSetSwitchState *>(type);
            setEcgDemoData(notification_ptr->m_state);
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
