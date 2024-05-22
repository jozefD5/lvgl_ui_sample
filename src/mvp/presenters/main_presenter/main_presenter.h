#pragma once
#include <models/demo_model/demo_model.h>
#include <views/main_view/main_view.h>
#include "lvgl/lvgl.h"


class MainPresenter : public IBaseView{
    private:
        MainView* view;              // View (UI)
        DemoModel* demoModel;        // Data model for this view.

    public:
        MainPresenter(MainView* view, DemoModel* demoModel);

        void updateAllValues(int val1, int val2);

        void notifyPresenter(void* p) override;
};
