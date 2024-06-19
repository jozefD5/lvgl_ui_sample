#include <iostream>
#include "main_tab_view.h"


namespace LvUi {

    MainTabView::MainTabView(BasePublisher *publisher)
    {
        m_publisher = publisher;
        m_model_ = static_cast<MainModel *>(m_publisher->getModel());
    }

    void MainTabView::init(lv_obj_t *active_view)
    {
        // Set tab view position and style.
        lv_obj_t* m_main_tab_view = lv_tabview_create(active_view);
        lv_tabview_set_tab_bar_position(m_main_tab_view, LV_DIR_BOTTOM);
        lv_tabview_set_tab_bar_size(m_main_tab_view, 50);
        lv_obj_set_width(m_main_tab_view, lv_pct(100));
        lv_obj_set_height(m_main_tab_view, lv_pct(100));
        lv_obj_set_align(m_main_tab_view, LV_ALIGN_CENTER);
        lv_obj_remove_flag(m_main_tab_view, LV_OBJ_FLAG_SCROLLABLE);

        lv_obj_set_style_text_color(lv_tabview_get_tab_bar(m_main_tab_view), lv_color_hex(0xFFFDFD), LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(lv_tabview_get_tab_bar(m_main_tab_view), 255, LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(lv_tabview_get_tab_bar(m_main_tab_view), lv_color_hex(0x3B7D98), LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(lv_tabview_get_tab_bar(m_main_tab_view), 255, LV_STATE_DEFAULT);

        // Setup tabs.
        m_model_->m_main_tab = lv_tabview_add_tab(m_main_tab_view, "Main");
        m_model_->m_ecg_tab = lv_tabview_add_tab(m_main_tab_view, "ECG");
        m_model_->m_oxygen_tab = lv_tabview_add_tab(m_main_tab_view, "Oxygen");
    }
}
