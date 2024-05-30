#include <iostream>
#include <unistd.h>
#include "ecg_view.h"
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"
#include <functional>
#include <actions/ecg/ecg_events.h>


namespace LvUi {

    EcgView::EcgView(const int32_t t_view_w, const int32_t t_view_h): m_view_width(t_view_w), m_view_height(t_view_h) {}


    void EcgView::button_event_callback(lv_event_t *e)
    {
        std::cout << "Button pressed: 1\n\r";
        // Cast pointer as view object pointer.
        void* void_presenter_ptr = lv_event_get_user_data(e);
        IBasePresenter* presenter_ptr = static_cast<IBasePresenter *>(void_presenter_ptr);

        NEcgButtonPressed eventNotification(0);
        presenter_ptr->notifyPresenter(&eventNotification);

    }


    void EcgView::create(void)
    {
        // Setup main container (grid) size and layout.
        auto container_width = m_view_width - (DEFAULT_PADING_PX * 2);
        auto container_height = m_view_height - (DEFAULT_PADING_PX * 2);

        m_container_col_dsc[0] = LV_GRID_FR(1);
        m_container_col_dsc[1] = LV_GRID_FR(1);
        m_container_col_dsc[2] = LV_GRID_FR(1);
        m_container_col_dsc[3] = LV_GRID_TEMPLATE_LAST;

        m_container_row_dsc[0] = TOP_ROW_HEIGHT_PX;
        m_container_row_dsc[1] = LV_GRID_FR(1);
        m_container_row_dsc[2] = LV_GRID_TEMPLATE_LAST;

        // Setup main container.
        m_container = lv_obj_create(lv_screen_active());
        lv_obj_set_style_grid_column_dsc_array(m_container, m_container_col_dsc, 0);
        lv_obj_set_style_grid_row_dsc_array(m_container, m_container_row_dsc, 0);
        lv_obj_set_size(m_container, container_width, container_height);
        lv_obj_center(m_container);
        lv_obj_set_layout(m_container, LV_LAYOUT_GRID);
        lv_obj_set_style_bg_color(m_container, lv_color_hex(BACKGROUN_COLOR), LV_PART_MAIN);
        lv_obj_set_style_border_color(m_container, lv_color_hex(BACKGROUN_COLOR), LV_PART_MAIN);
        lv_obj_align(m_container, LV_ALIGN_CENTER, 0, 0);


        // Title.
        lv_obj_t *chart_lb = lv_label_create(m_container);
        lv_label_set_text(chart_lb, "ECG Waveform");
        lv_obj_set_style_text_color(chart_lb, lv_color_hex(0xffffff), LV_PART_MAIN);
        lv_obj_set_style_text_font(chart_lb, &lv_font_montserrat_38, LV_PART_MAIN);
        lv_obj_set_grid_cell(chart_lb, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_START, 0, 1);


        // Control button.
        control_btn = lv_button_create(m_container);
        lv_obj_set_grid_cell(control_btn, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
        lv_obj_add_event_cb(control_btn, this->button_event_callback, LV_EVENT_PRESSED, subscriber);
        lv_obj_t *control_btn_label = lv_label_create(control_btn);
        lv_label_set_text(control_btn_label, "Start / Stop");


        // ECG chart.
        m_ecg_chart = lv_chart_create(m_container);
        lv_obj_set_grid_cell(m_ecg_chart, LV_GRID_ALIGN_START, 0, 3, LV_GRID_ALIGN_STRETCH, 1, 1);
        lv_obj_set_style_radius(m_ecg_chart, 10, LV_PART_MAIN);
        lv_obj_set_style_border_color(m_ecg_chart, lv_color_hex(CHART_BACKGROUND_COLOR), LV_PART_MAIN);
        lv_obj_set_style_bg_color(m_ecg_chart, lv_color_hex(CHART_BACKGROUND_COLOR), LV_PART_MAIN);

        m_ecg_series = lv_chart_add_series(m_ecg_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);

        // Add demo data.
        for(uint32_t i = 0; i < 200; i++) {
            lv_chart_set_next_value(m_ecg_chart, m_ecg_series, lv_rand(-20, 70));
        }

    }


    void EcgView::updateLabel1(std::string str) {
        // lv_label_set_text(mainLabel, str.c_str());
    }

}
