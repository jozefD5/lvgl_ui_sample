#include <iostream>
#include "main_presenter.h"



MainPresenter::MainPresenter(lv_obj_t* view, DemoModel* demoModel): view(view), demoModel(demoModel) {}


void MainPresenter::updateAllValues(int val1, int val2) {
    demoModel->setValue1(val1);
    demoModel->setValue2(val2);

    // TODO add view (UI) update.
}
