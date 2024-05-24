#include <iostream>
#include <unistd.h>
#include "main_view.h"
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"
#include <functional>

#define BACKGROUN_COLOR                0x001d3d
#define CHART_BACKGROUND_COLOR         0x003566


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

        // Grid.
        static int32_t col_dsc[] = {900, 300, LV_GRID_TEMPLATE_LAST};
        static int32_t row_dsc[] = {350, 350, LV_GRID_TEMPLATE_LAST};

        // Background color.
        lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(BACKGROUN_COLOR), LV_PART_MAIN);

        // Create a container with grid.
        lv_obj_t * cont = lv_obj_create(lv_screen_active());
        lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
        lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
        lv_obj_set_size(cont, 1270, 710);
        lv_obj_center(cont);
        lv_obj_set_layout(cont, LV_LAYOUT_GRID);

        static lv_style_t grid_style;
        lv_style_init(&grid_style);
        lv_style_set_bg_color(&grid_style, lv_color_hex(BACKGROUN_COLOR));
        lv_style_set_border_color(&grid_style,lv_color_hex(BACKGROUN_COLOR));
        lv_obj_add_style(cont, &grid_style,LV_PART_MAIN);


        // Initilize chart.
        chart = lv_chart_create(cont);
        lv_obj_set_size(chart, 900, 350);
        lv_obj_set_grid_cell(chart, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

        static lv_style_t chart_style;
        lv_style_init(&chart_style);
        lv_style_set_radius(&chart_style, 10);
        lv_style_set_border_color(&chart_style,lv_color_hex(CHART_BACKGROUND_COLOR));
        lv_style_set_bg_color(&chart_style, lv_color_hex(CHART_BACKGROUND_COLOR));

        ser = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
        uint32_t i;
        for(i = 0; i < 200; i++) {
            lv_chart_set_next_value(chart, ser, lv_rand(-20, 70));
        }

        // ESG label and background object.
        static lv_style_t lb_bg_style;
        lv_style_init(&lb_bg_style);
        lv_style_set_size(&lb_bg_style, 200, 25);
        lv_style_set_border_color(&lb_bg_style,lv_color_hex(CHART_BACKGROUND_COLOR));
        lv_style_set_bg_color(&lb_bg_style, lv_color_hex(CHART_BACKGROUND_COLOR));

        // Create an object with the new style.
        lv_obj_t * lb_bg_obj = lv_obj_create(chart);
        lv_obj_add_style(lb_bg_obj, &lb_bg_style, 0);

        lv_obj_t * chart_lb = lv_label_create(lb_bg_obj);
        lv_label_set_text(chart_lb, "ECG Waveform");
        lv_obj_set_style_text_align(chart_lb, LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_align(chart_lb, LV_ALIGN_CENTER, 0, 0);

        static lv_style_t chart_label_style;
        lv_style_set_text_color(&chart_label_style, lv_color_hex(0xffffff));
        lv_obj_add_style(chart_lb, &chart_label_style,LV_PART_MAIN);
        lv_obj_add_style(chart, &chart_style, LV_PART_MAIN);






        // Heart beat label.
        static lv_style_t lb_hb_bg_style;
        lv_style_init(&lb_hb_bg_style);
        lv_style_set_size(&lb_hb_bg_style, 200, 25);
        lv_style_set_border_color(&lb_hb_bg_style,lv_color_hex(CHART_BACKGROUND_COLOR));
        lv_style_set_bg_color(&lb_hb_bg_style, lv_color_hex(CHART_BACKGROUND_COLOR));

        // Create an object with the new style.
        lv_obj_t * lb_hb_bg_obj = lv_obj_create(cont);
        lv_obj_add_style(lb_hb_bg_obj, &lb_hb_bg_style, 0);
        lv_obj_set_grid_cell(lb_hb_bg_obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

        lv_obj_t * hb_label = lv_label_create(lb_hb_bg_obj);
        lv_label_set_text(hb_label, "120");
        lv_obj_set_style_text_align(hb_label, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_align(hb_label, LV_ALIGN_CENTER, 0, 0);

        static lv_style_t style;
        lv_style_init(&style);
        lv_style_set_text_font(&style, &lv_font_montserrat_10);
        lv_obj_add_style(hb_label, &style, 0);


        // lv_obj_t * chart_lb = lv_label_create(lb_bg_obj);
        // lv_label_set_text(chart_lb, "HB");
        // lv_obj_set_style_text_align(chart_lb, LV_TEXT_ALIGN_LEFT, 0);
        // lv_obj_align(chart_lb, LV_ALIGN_CENTER, 0, 0);

        // static lv_style_t chart_label_style;
        // lv_style_set_text_color(&chart_label_style, lv_color_hex(0xffffff));
        // lv_obj_add_style(chart_lb, &chart_label_style,LV_PART_MAIN);
        // lv_obj_add_style(chart, &chart_style, LV_PART_MAIN);







    }





    void MainView::updateLabel1(std::string str) {
        // lv_label_set_text(mainLabel, str.c_str());
    }

}
