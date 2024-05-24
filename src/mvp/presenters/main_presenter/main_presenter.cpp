#include <iostream>
#include <string>
#include "main_presenter.h"


namespace LvUi {

    MainPresenter::MainPresenter(MainView* view, DemoModel* demoModel): view(view), demoModel(demoModel) {
        view->setSubscriber(this);
        view->create();
    }

    void MainPresenter::updateAllValues(int val1, int val2) {
        demoModel->setValue1(val1);
        demoModel->setValue2(val2);

        std::string str1 = "Val1: " + std::to_string(val1);
        view->updateLabel1(str1);
    }

    void MainPresenter::notifyPresenter(void* p) {
        std::cout << "Button Pressed!\n\r";

        updateAllValues(
            this->demoModel->getValue1()+1,
            this->demoModel->getValue2()+1
        );
    }
}
