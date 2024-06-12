#pragma once
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"
#include "lvgl/lvgl.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Main tab view, provides bottom tabs for Main, ECG and Oxygen tabs.
     *
     ******************************************************************************/
    class MainTabView : public IBaseSubscriber {
        public:
            // Pointer to presenter's model (data).
            MainModel *m_model_;

        public:
            /*******************************************************************************
             * @brief Construct a new Main Tab View object
             *
             * @param publisher pointer to publisher for bi-directional communication.
             *
             ******************************************************************************/
            MainTabView(IBasePublisher *publisher);

            /*******************************************************************************
             * @brief Initialise core components and create UI.
             *
             * @param active_view pointer to active screen/view widget.
             *
             ******************************************************************************/
            void init(lv_obj_t *active_view);
    };
}
