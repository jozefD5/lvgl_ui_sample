#pragma once
#include <iostream>
#include <unistd.h>
#include <vector>
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"

namespace LvUi {

    class EcgView : public IBaseView {
        private:
            // std::vector<int32_t> m_container_col_dsc;       // Container columns.
            // std::vector<int32_t> m_container_row_dsc;       // Container rows.
            lv_obj_t *m_container;                          // Container.
            lv_obj_t *m_ecg_chart;                          // ECG chart.
            lv_chart_series_t *m_ecg_series;                // ECG data series.
            lv_obj_t *control_btn;                          // Enable / disable button.

        private:
            void initEcgChart(const int32_t t_view_w, const int32_t t_view_h);

        public:
            EcgView(const int32_t t_view_w, const int32_t t_view_h);
            ~EcgView() = default;

            void create(const int32_t t_view_w, const int32_t t_view_h);

            void updateLabel1(std::string str);
    };

}
