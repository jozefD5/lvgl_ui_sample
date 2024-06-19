#pragma once
#include "mvp/interfaces/base_pub_sub.hpp"
#include "lvgl/lvgl.h"

namespace LvUi {

    /*******************************************************************************
     * @brief Main application model, holds key application data that are shared
     *        between multiple views.
     *
     ******************************************************************************/
    class MainModel {
        public:
            // Main tab view and tabs
            lv_obj_t *m_main_tab;
            lv_obj_t *m_ecg_tab;
            lv_obj_t *m_oxygen_tab;

            // Main menu data
            lv_obj_t *m_main_ecg_chart;
            lv_obj_t *m_main_oxygen_chart;
            lv_chart_series_t *m_main_ecg_chart_series;
            lv_chart_series_t *m_main_oxygen_chart_series;

            // ECG data.
            lv_timer_t *m_ecg_data_timer;
            lv_obj_t *m_ecg_chart;
            lv_chart_series_t *m_ecg_chart_series;

            // Oxygen data.
            lv_timer_t *m_oxygen_data_timer;
            lv_obj_t *m_oxygen_chart;
            lv_chart_series_t *m_oxygen_chart_series;


    };
}
