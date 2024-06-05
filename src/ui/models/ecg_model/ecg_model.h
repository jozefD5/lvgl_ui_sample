#pragma once
#include "mvp/interfaces/i_base_mvp.h"
#include "lvgl/lvgl.h"


namespace LvUi {

    /*******************************************************************************
     * @brief Ecg view data model, includes all data associated with ECG view.
     *
     ******************************************************************************/
    class EcgModel : public BaseMvp::IBaseModel{
        public:
            int32_t m_view_width;                   // View / container's width in pixels
            int32_t m_view_height;                  // View / container's height in pixels
            bool m_ecg_demo_enabled;                // Enable / disable demo data generation.
            lv_timer_t *m_ecg_timer;                // LVGL timer.
            lv_chart_series_t *m_ecg_series;        // LVGL chart series (data).
        public:
            EcgModel(int32_t view_width, int32_t m_view_height);

    };
}
