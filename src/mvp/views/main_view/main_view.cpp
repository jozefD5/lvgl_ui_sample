#include <iostream>
#include <unistd.h>
#include "main_view.h"
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"



static void btn1_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

MainView::MainView() {}

void MainView::create() {
    lv_obj_t* label1;

    mainBtn = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(mainBtn, btn1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(mainBtn, LV_ALIGN_CENTER, 0, -40);

    label1 = lv_label_create(mainBtn);
    lv_label_set_text(label1, "+");
    lv_obj_center(label1);

    mainLabel = lv_label_create(lv_scr_act());
    lv_label_set_text(mainLabel, "Txt: ");
    lv_obj_center(mainLabel);
    lv_obj_align(mainBtn, LV_ALIGN_CENTER, 0, -40);
}

void MainView::setSubscriber(IBaseView* ss) {
    this->subscriber = ss;
}

void MainView::updateLabel1(std::string str) {
    lv_label_set_text(mainLabel, str.c_str());
}
