#pragma once
#include "lvgl/lvgl.h"


namespace LvUi {

    class EcgModel {
        public:
            bool ecg_demo_enabled;
            lv_timer_t *ecg_timer;

        public:
            EcgModel(void);

    };
}
