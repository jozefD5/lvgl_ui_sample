#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Main application presenter, handles core application business logic.
     *
     ******************************************************************************/
    class MainPresenter : public IBasePublisher{
        public:
            MainModel *m_dataModel_;

        public:
            /*******************************************************************************
             * @brief Construct a new Main Presenter object
             *
             * @param dataModel pointer to data model that holds presenter's data.
             *
             ******************************************************************************/
            MainPresenter(MainModel *dataModel);

            void onSubscriberData(IBaseNotificationType type) override;

            void* getModel(void) override;
    };
}
