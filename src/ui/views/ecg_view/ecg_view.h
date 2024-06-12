#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"
#include "presenters/main_presenter.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief ECG view, displays ECG data.
     *
     ******************************************************************************/
    class EcgView : public IBaseSubscriber
    {
        private:

            MainModel *m_model_;       // Pointer to presenter's model (data).
            lv_obj_t *m_ecg_switch;    // ECG enable/disable switch.

        private:
            /*******************************************************************************
             * @brief Static function used as call back for switch.
             *
             ******************************************************************************/
            static void switch_event_callback(lv_event_t *e);

        public:
            /*******************************************************************************
             * @brief Construct a new Ecg View object
             *
             * @param publisher pointer to publisher for bi-directional communication.
             *
             ******************************************************************************/
            EcgView(IBasePublisher *publisher);

            /*******************************************************************************
             * @brief Initialise core components and create UI.
             *
             ******************************************************************************/
            void init(void);
    };
}
