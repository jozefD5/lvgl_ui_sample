#pragma once
#include <iostream>
#include <unistd.h>
#include <vector>
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"

namespace LvUi {

    class EcgView : public IBaseView {
        private:
            std::vector<int32_t> m_container_col_dsc;      // container columns.
            std::vector<int32_t> m_container_row_dsc;      // Container rows.
            lv_obj_t * m_container;                        // Container.

            // lv_obj_t* mainBtn;
            // lv_obj_t* mainLabel;

        private:

        public:
            EcgView(int32_t t_view_w, int32_t t_view_h);
            ~EcgView() = default;

            void create(int32_t t_view_w, int32_t t_view_h);

            void updateLabel1(std::string str);
    };

}
