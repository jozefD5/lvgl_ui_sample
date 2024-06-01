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
        // TODO, set as private.
        public:
            int32_t m_view_width;                           // View / container's width in pixels
            int32_t m_view_height;                          // View / container's height in pixels
            int32_t m_container_col_dsc[4];                 // Container columns.
            int32_t m_container_row_dsc[3];                 // Container rows.
            lv_obj_t *m_container;                          // Container.
            lv_obj_t *m_ecg_chart;                          // ECG chart.
            lv_obj_t *control_btn;                          // Enable / disable button.

        private:
            /*******************************************************************************
             * @brief Static function used as call back for LVGL events.
             ******************************************************************************/
            static void button_event_callback(lv_event_t *e);

        public:
            /*******************************************************************************
             * @brief Construct a new Ecg View object
             *
             * @param t_view_w view width in pixels.
             * @param t_view_h view heigth in pixels.
             *
             ******************************************************************************/
            EcgView(const int32_t t_view_w, const int32_t t_view_h);
            ~EcgView() = default;

            /*******************************************************************************
             * @brief Initiate UI.
             ******************************************************************************/
            void create(void);

    };

}
