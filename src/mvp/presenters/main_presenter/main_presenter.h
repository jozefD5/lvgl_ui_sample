#pragma once
#include <models/demo_model/demo_model.h>
#include "lvgl/lvgl.h"

class MainPresenter {
    private:
        lv_obj_t* view;
        DemoModel* demoModel;

    public:
        MainPresenter(lv_obj_t* view, DemoModel* demoModel);

        void updateAllValues(int val1, int val2);



};
