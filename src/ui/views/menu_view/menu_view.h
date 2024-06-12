#pragma once
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"
#include "lvgl/lvgl.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Main menu tab, displays ecg and oxygen data.
     *
     ******************************************************************************/
    class MenuView : public IBaseSubscriber {
        public:
            // Pointer to presenter's model (data).
            MainModel *m_model_;

        public:
            /*******************************************************************************
             * @brief Construct a new Menu View object
             *
             * @param publisher pointer to publisher for bi-directional communication.
             *
             ******************************************************************************/
            MenuView(IBasePublisher *publisher);

            /*******************************************************************************
             * @brief Initialise core components and create UI.
             *
             ******************************************************************************/
            void init(void);

    };
}
