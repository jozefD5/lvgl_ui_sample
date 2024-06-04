#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"
#include "views/main_tab/main_tab_view.h"


namespace LvUi {

    /*******************************************************************************
     * @brief Main tab view presenter.
     *
     ******************************************************************************/
    class MainTabPresenter : public BaseMvp::IBasePresenter {
        private:
            MainTabView *m_view;
            // MainTabModel * m_model;

        public:
            /*******************************************************************************
             * @brief Construct a new Main Tab Presenter object.
             *
             * @param view view associated new presenter.
             * @param parent_widget parent widget for view.
             *
             ******************************************************************************/
            MainTabPresenter(MainTabView* view, lv_obj_t *parent_widget);

            void notifyPresenter(const BaseMvp::IBaseNotificationEvent* p) override;

    };

}
