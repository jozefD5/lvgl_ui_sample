#pragma once
#include <iostream>
#include <unistd.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"


class MainView {
    private:
        lv_obj_t* mainBtn;
        lv_obj_t* mainLabel;
        IBaseView* subscriber;

    private:
        static void button_event_callback(lv_event_t *e);

    public:
        MainView();
        ~MainView() = default;

        void create();

        void setSubscriber(IBaseView* ss);

        void updateLabel1(std::string str);


};
