#pragma once
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"
#include "lvgl/lvgl.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Oxygen data view.
     *
     ******************************************************************************/
    class OxygenView : public IBaseSubscriber {
        public:
            // Pointer to presenter's model (data).
            MainModel *m_model_;

        public:
            /*******************************************************************************
             * @brief Construct a new Oxygen View object
             *
             * @param publisher pointer to publisher for bi-directional communication.
             *
             ******************************************************************************/
            OxygenView(IBasePublisher *publisher);

            /*******************************************************************************
             * @brief Initialise core components and create UI.
             *
             ******************************************************************************/
            void init(void);
    };

}
