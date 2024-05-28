#include <iostream>
#include <string>
#include "ecg_presenter.h"
#include "views/ecg_view/ecg_view.h"


namespace LvUi {

    EcgPresenter::EcgPresenter(EcgView* view, EcgModel* ecgModel): view(view), ecgModel(ecgModel) {
        view->setSubscriber(this);
        view->create();
    }

    void EcgPresenter::updateAllValues(int val1, int val2) {
        ecgModel->setValue1(val1);
        ecgModel->setValue2(val2);

        std::string str1 = "Val1: " + std::to_string(val1);
        view->updateLabel1(str1);
    }

    void EcgPresenter::notifyPresenter(void* p) {
        std::cout << "Button Pressed!\n\r";

        updateAllValues(
            this->ecgModel->getValue1()+1,
            this->ecgModel->getValue2()+1
        );
    }
}
