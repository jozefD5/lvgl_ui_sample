#pragma once
#include <iostream>
#include <unistd.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"

namespace LvUi {

    class EcgView : public IBaseView {
        private:
            // lv_obj_t* mainBtn;
            // lv_obj_t* mainLabel;

        private:
            static void button_event_callback(lv_event_t *e);

        public:
            EcgView();
            ~EcgView() = default;

            void create();

            void updateLabel1(std::string str);
    };

}
