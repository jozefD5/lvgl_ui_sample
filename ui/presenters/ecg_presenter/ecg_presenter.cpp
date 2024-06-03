#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "ecg_presenter.h"
#include "views/ecg_view/ecg_view.h"
#include "actions/ecg/ecg_events.h"


namespace LvUi {

    EcgPresenter::EcgPresenter(EcgView* view, EcgModel* ecgModel): view(view), model(ecgModel) {
        // Set view's presenter subscriber.
        view->setSubscriber(this);

        // Create view (UI).
        view->create(ecgModel->m_view_width, ecgModel->m_view_height);

        // Init model data.
        model->m_ecg_series = lv_chart_add_series(view->m_ecg_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);

        // Setup ecg timer.
        model->m_ecg_timer = lv_timer_create(ecg_demo_data_timer_handler, 100, this);
        lv_timer_pause(model->m_ecg_timer);
    }

    // ECG demo data timer handler, generates demo data as set time interval.
    void EcgPresenter::ecg_demo_data_timer_handler(lv_timer_t *timer)
    {
        // Cast pointer as ecg presenter object.
        void* data = timer->user_data;
        EcgPresenter* presenter_ptr = static_cast<EcgPresenter *>(data);

        // Update model.
        std::cout << "ECG demo running ...\n\r";
        lv_chart_set_next_value(presenter_ptr->view->m_ecg_chart, presenter_ptr->model->m_ecg_series, lv_rand(3, 50));

        // Notify view.
        NEcgSSButtonPressed eventNotification(StartStopButtonPressed);
        presenter_ptr->view->notifyView(&eventNotification);
    }

    /*******************************************************************************
     * @brief Notify presenter of any UI changes.
     *
     * @param p pointer to notification object that holds and action specific data.
     *
     ******************************************************************************/
    void EcgPresenter::notifyPresenter(const BaseMvp::IBaseNotificationEvent* p)
    {
        switch(p->notificationType)
        {
            // Start / Stop button pressed.
            case StartStopButtonPressed:
                model->m_ecg_demo_enabled = !model->m_ecg_demo_enabled;
                std::cout << "Ecg enabled: " << model->m_ecg_demo_enabled << std::endl;

                if(model->m_ecg_demo_enabled) {
                    lv_timer_resume(model->m_ecg_timer);
                }else{
                    lv_timer_pause(model->m_ecg_timer);
                }


            default:
                break;
        }

    }

}
