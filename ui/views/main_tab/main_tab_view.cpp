#include <iostream>
#include "main_tab_view.h"
#include "main.h"
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"


namespace LvUi {

    void MainTabView::create(lv_obj_t *parent_widget)
    {
        // Create tab view.
        m_tab_view = lv_tabview_create(parent_widget);
        lv_tabview_set_tab_bar_position(m_tab_view, LV_DIR_BOTTOM);
        lv_tabview_set_tab_bar_size(m_tab_view, 50);

        // Set style.
        lv_obj_set_style_bg_color(m_tab_view, lv_color_hex(MAIN_VIEW_BACKGROUN_COLOR), LV_PART_MAIN);
        lv_obj_set_style_border_color(m_tab_view, lv_color_hex(MAIN_VIEW_BACKGROUN_COLOR), LV_PART_MAIN);

        lv_obj_t * tab_buttons = lv_tabview_get_tab_bar(m_tab_view);
        lv_obj_set_style_bg_color(tab_buttons, lv_palette_darken(LV_PALETTE_BLUE, 2), 0);
        lv_obj_set_style_text_color(tab_buttons, lv_palette_lighten(LV_PALETTE_GREY, 4), 0);
        lv_obj_set_style_border_side(tab_buttons, LV_BORDER_SIDE_TOP, LV_STATE_CHECKED | LV_STATE_PRESSED);

        // Add tabs.
        m_tab_main_menu = lv_tabview_add_tab(m_tab_view, "Main Menu");
        m_tab_ecg = lv_tabview_add_tab(m_tab_view, "ECG");
        m_tab_oxygen = lv_tabview_add_tab(m_tab_view, "Oxygen");
    }

    void MainTabView::notifyView(const BaseMvp::IBaseNotificationEvent *p)
    {
    }

}
