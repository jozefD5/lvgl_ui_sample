#include <iostream>
#include <unistd.h>
#include "ecg_view.h"
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"
#include <functional>

#define BACKGROUN_COLOR                0x001d3d
#define CHART_BACKGROUND_COLOR         0x003566



namespace LvUi {


    EcgView::EcgView(int32_t t_view_w, int32_t t_view_h)
    {
        int32_t width_length = (t_view_w - 10) / 4;   // Use 10px as safe are.
        int32_t centre_hight = t_view_h - 110;        // 100px for header and 10 for safe area.

        // configure container.
        int32_t col_dsc[] = {width_length, width_length, width_length, width_length, LV_GRID_TEMPLATE_LAST};
        int32_t row_dsc[] = {100, centre_hight, LV_GRID_TEMPLATE_LAST};

        auto col_size = sizeof(col_dsc) / sizeof(col_dsc[0]);
        auto row_size = sizeof(row_dsc) / sizeof(row_dsc[0]);

        std::copy(col_dsc, col_dsc + col_size, std::back_inserter(m_container_col_dsc));
        std::copy(col_dsc, col_dsc + col_size, std::back_inserter(m_container_row_dsc));

        create(t_view_w, t_view_h);
    }

    /*
    void EcgView::button_event_callback(lv_event_t *e)
    {
        // Cast pointer as view object pointer.
        void* void_view_ptr = lv_event_get_user_data(e);
        IBasePresenter* view_ptr = static_cast<IBasePresenter *>(void_view_ptr);

        view_ptr->notifyPresenter(NULL);
    }
    */


    void EcgView::create(int32_t t_view_w, int32_t t_view_h)
    {
        static lv_obj_t * chart;
        static lv_chart_series_t * ser;
        static lv_chart_cursor_t * cursor;

        // Main view background color.
        lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(BACKGROUN_COLOR), LV_PART_MAIN);

        // Setup main container.
        m_container = lv_obj_create(lv_screen_active());
        lv_obj_set_style_grid_column_dsc_array(m_container, &m_container_col_dsc[0], 0);
        lv_obj_set_style_grid_row_dsc_array(m_container, &m_container_row_dsc[0], 0);
        lv_obj_set_size(m_container, t_view_w, t_view_h);
        lv_obj_center(m_container);
        lv_obj_set_layout(m_container, LV_LAYOUT_GRID);
        lv_obj_set_style_bg_color(m_container, lv_color_hex(BACKGROUN_COLOR), LV_PART_MAIN);
        lv_obj_set_style_border_color(m_container, lv_color_hex(BACKGROUN_COLOR), LV_PART_MAIN);




        // Initialize chart.
        chart = lv_chart_create(m_container);
        lv_obj_set_size(chart, 900, 350);
        lv_obj_set_grid_cell(chart, LV_GRID_ALIGN_STRETCH, 0, 4, LV_GRID_ALIGN_STRETCH, 1, 1);

        static lv_style_t chart_style;
        lv_style_init(&chart_style);
        lv_style_set_radius(&chart_style, 10);
        lv_style_set_border_color(&chart_style,lv_color_hex(CHART_BACKGROUND_COLOR));
        lv_style_set_bg_color(&chart_style, lv_color_hex(CHART_BACKGROUND_COLOR));
        lv_obj_add_style(chart, &chart_style, LV_PART_MAIN);

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

        lv_obj_t * lb_bg_obj = lv_obj_create(chart);
        lv_obj_add_style(lb_bg_obj, &lb_bg_style, 0);

        lv_obj_t * chart_lb = lv_label_create(lb_bg_obj);
        lv_label_set_text(chart_lb, "ECG Waveform");
        lv_obj_set_style_text_align(chart_lb, LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_align(chart_lb, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_text_color(chart_lb, lv_color_hex(0xffffff), LV_PART_MAIN);








        // // Heart beat label.
        // static lv_style_t lb_hb_bg_style;
        // lv_style_init(&lb_hb_bg_style);
        // lv_style_set_size(&lb_hb_bg_style, 200, 25);
        // lv_style_set_border_color(&lb_hb_bg_style,lv_color_hex(CHART_BACKGROUND_COLOR));
        // lv_style_set_bg_color(&lb_hb_bg_style, lv_color_hex(CHART_BACKGROUND_COLOR));

        // // Create an object with the new style.
        // lv_obj_t * lb_hb_bg_obj = lv_obj_create(m_container);
        // lv_obj_add_style(lb_hb_bg_obj, &lb_hb_bg_style, 0);
        // lv_obj_set_grid_cell(lb_hb_bg_obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

        // lv_obj_t * hb_label = lv_label_create(lb_hb_bg_obj);
        // lv_label_set_text(hb_label, "120");
        // lv_obj_set_style_text_align(hb_label, LV_TEXT_ALIGN_CENTER, 0);
        // lv_obj_align(hb_label, LV_ALIGN_LEFT_MID, 10, 0);
        // lv_obj_set_style_text_font(hb_label, &lv_font_montserrat_48, LV_PART_MAIN);
        // lv_obj_set_style_text_color(hb_label, lv_color_hex(0xffffff), LV_PART_MAIN);

        // lv_obj_t * hb_label_bmp = lv_label_create(lb_hb_bg_obj);
        // lv_label_set_text(hb_label_bmp, "bmp");
        // lv_obj_set_style_text_align(hb_label_bmp, LV_TEXT_ALIGN_CENTER, 0);
        // lv_obj_align(hb_label_bmp, LV_ALIGN_RIGHT_MID, 10, 0);
        // lv_obj_set_style_text_font(hb_label_bmp, &lv_font_montserrat_40, LV_PART_MAIN);
        // lv_obj_set_style_text_color(hb_label_bmp, lv_color_hex(0xffffff), LV_PART_MAIN);


    }





    void EcgView::updateLabel1(std::string str) {
        // lv_label_set_text(mainLabel, str.c_str());
    }

}
