#include <iostream>
#include <unistd.h>
#include "main_view.h"
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"
#include <functional>


MainView::MainView() {}

void MainView::button_event_callback(lv_event_t *e)
{
    // Cast pointer as view object pointer.
    void* void_view_ptr = lv_event_get_user_data(e);
    IBaseView* view_ptr = static_cast<IBaseView *>(void_view_ptr);

    view_ptr->notifyPresenter(NULL);
}

void MainView::create() {
    lv_obj_t* label1;

    // TODO, add try if subscriber is null.

    mainBtn = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(mainBtn, this->button_event_callback, LV_EVENT_PRESSED, subscriber);
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
