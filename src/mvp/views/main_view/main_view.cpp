#include <iostream>
#include <unistd.h>
#include "main_view.h"
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"
#include <functional>

namespace LvUi {

    MainView::MainView() {}

    void MainView::button_event_callback(lv_event_t *e)
    {
        // Cast pointer as view object pointer.
        void* void_view_ptr = lv_event_get_user_data(e);
        IBasePresenter* view_ptr = static_cast<IBasePresenter *>(void_view_ptr);

        view_ptr->notifyPresenter(NULL);
    }

    void MainView::create() {
        static lv_obj_t * chart;
        static lv_chart_series_t * ser;
        static lv_chart_cursor_t * cursor;

        chart = lv_chart_create(lv_screen_active());
        lv_obj_set_size(chart, 700, 500);
        lv_obj_align(chart, LV_ALIGN_CENTER, 0, -10);

        // lv_obj_add_event_cb(chart, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
        lv_obj_refresh_ext_draw_size(chart);

        cursor = lv_chart_add_cursor(chart, lv_palette_main(LV_PALETTE_BLUE), LV_DIR_LEFT | LV_DIR_BOTTOM);

        ser = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
        uint32_t i;
        for(i = 0; i < 10; i++) {
            lv_chart_set_next_value(chart, ser, lv_rand(10, 90));
        }

        //    lv_chart_set_scale_x(chart, 500);

        lv_obj_t * label = lv_label_create(lv_screen_active());
        lv_label_set_text(label, "Click on a point");
        lv_obj_align_to(label, chart, LV_ALIGN_OUT_TOP_MID, 0, -5);

        }

        void MainView::updateLabel1(std::string str) {
            // lv_label_set_text(mainLabel, str.c_str());
        }

}
