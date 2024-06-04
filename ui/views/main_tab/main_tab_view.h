#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"

namespace LvUi {

    class MainTabView : public BaseMvp::IBaseView{

        private:
            lv_obj_t *m_tab_view;           // Tab view.
            lv_obj_t *m_tab_main_menu;      // Main menu tab.
            lv_obj_t *m_tab_ecg;            // ECG tab.
            lv_obj_t *m_tab_oxygen;         // Oxygen tab.

        public:
            void notifyView(const BaseMvp::IBaseNotificationEvent* p) override;

            void create(lv_obj_t *parent_widget);

    };

}
