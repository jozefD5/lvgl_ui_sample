#pragma once
#include "lvgl/lvgl.h"


namespace LvUi {

    class EcgModel {
        public:
            bool m_ecg_demo_enabled;
            lv_timer_t *m_ecg_timer;
            lv_chart_series_t *m_ecg_series;
        public:
            EcgModel(void);

    };
}
