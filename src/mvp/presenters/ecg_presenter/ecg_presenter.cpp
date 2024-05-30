#include <iostream>
#include <string>
#include "ecg_presenter.h"
#include "views/ecg_view/ecg_view.h"


namespace LvUi {

    EcgPresenter::EcgPresenter(EcgView* view, EcgModel* ecgModel): view(view), ecgModel(ecgModel) {
        view->setSubscriber(this);
        view->create();
    }

    void EcgPresenter::notifyPresenter(const IBaseNotificationEvent* p)
    {
        if(p->notificationType == 0) {
            std::cout << "Button pressed !!!\n\r";
        }
    }

}
