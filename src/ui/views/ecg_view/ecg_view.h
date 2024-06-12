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
            // Pointer to presenter's model (data).
            MainModel *m_model_;

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
