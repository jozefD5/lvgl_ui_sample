#pragma once
#include "mvp/interfaces/base_pub_sub.h"
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

            // ECG data.
            lv_timer_t *m_ecg_data_timer;
            lv_obj_t *m_ecg_chart;
            lv_chart_series_t *m_ecg_chart_series;
    };
}
