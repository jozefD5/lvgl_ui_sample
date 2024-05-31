#include <iostream>
#include <string>
#include "ecg_presenter.h"
#include "views/ecg_view/ecg_view.h"


namespace LvUi {

    // ECG demo data timer handler, generates demo data as set time interval.
    static void ecg_demo_data_timer_handler(lv_timer_t *timer)
    {
        std::cout << "ECG demo running ...\n\r";
    }

    EcgPresenter::EcgPresenter(EcgView* view, EcgModel* ecgModel): view(view), state(ecgModel) {
        view->setSubscriber(this);
        view->create();

        // Setup ecg timer.
        state->ecg_timer = lv_timer_create(ecg_demo_data_timer_handler, 500, NULL);
    }

    void EcgPresenter::notifyPresenter(const IBaseNotificationEvent* p)
    {
        // Enable/ disable ecg dema data timer.
        if(p->notificationType == StartStopButtonPressed) {
            state->ecg_demo_enabled = !state->ecg_demo_enabled;
            std::cout << "Ecg enabled: " << state->ecg_demo_enabled << std::endl;

            if(state->ecg_demo_enabled) {
                lv_timer_resume(state->ecg_timer);
            }else{
                lv_timer_pause(state->ecg_timer);
            }
        }
    }

}
