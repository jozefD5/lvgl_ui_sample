#pragma once
#include <iostream>
#include <unistd.h>
#include <vector>
#include "lvgl/lvgl.h"
#include "interfaces/base_view/i_base_view.h"

// TODO, move general style to style header.
// Use 100px for header.
#define TOP_ROW_HEIGHT_PX              50U

// Style. default
#define DEFAULT_PADING_PX              10U
#define BACKGROUN_COLOR                0x001d3d
#define CHART_BACKGROUND_COLOR         0x003566



namespace LvUi {

    class EcgView : public IBaseView {
        private:
            int32_t m_container_col_dsc[4];                 // Container columns.
            int32_t m_container_row_dsc[3];                 // Container rows.
            lv_obj_t *m_container;                          // Container.
            lv_obj_t *m_ecg_chart;                          // ECG chart.
            lv_chart_series_t *m_ecg_series;                // ECG data series.
            lv_obj_t *control_btn;                          // Enable / disable button.

        private:

        public:
            EcgView(const int32_t t_view_w, const int32_t t_view_h);
            ~EcgView() = default;

            void create(const int32_t t_view_w, const int32_t t_view_h);

            void updateLabel1(std::string str);
    };

}
