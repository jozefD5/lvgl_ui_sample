#define _DEFAULT_SOURCE /* needed for usleep() */
#include <iostream>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.hpp"
#include "ui/models/main_model.hpp"
#include "ui/presenters/main_presenter.hpp"
#include "ui/views/main_tab/main_tab_view.hpp"

#define SCREEN_SIZE_W     800
#define SCREEN_SIZE_H     480

/**
 * TODO,
 *     * add styling to specific class.
 *     * interface should pass by reference not by value.
 */


/*******************************************************************************
 * @brief Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 *        library
 *
 * @param w  display width in pixels
 * @param h  display height in pixels
 *
 * @return lv_display_t* pointer to structure representing display.
 ******************************************************************************/
static lv_display_t * hal_init(int32_t w, int32_t h);




int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    // Initialize LVGL.
    lv_init();

    // Initialize the HAL (display, input devices, tick) for LVGL.
    hal_init(SCREEN_SIZE_W, SCREEN_SIZE_H);

    lv_disp_t * dispp = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp,
                                               lv_palette_main(LV_PALETTE_BLUE),
                                               lv_palette_main(LV_PALETTE_RED),
                                               false,
                                               LV_FONT_DEFAULT);

    lv_disp_set_theme(dispp, theme);
    static lv_obj_t* active_screen = lv_obj_create(NULL);

    // Initialize model and publisher.
    LvUi::MainModel mainModel;
    LvUi::MainPresenter mainPresenter(&mainModel);

    // Main tab view.
    auto mainTabiew = std::make_shared<LvUi::MainTabView>(&mainPresenter);
    mainPresenter.subscribe(mainTabiew);
    mainTabiew->init(active_screen);

    // // Menu tab.
    // auto menuTab = std::make_shared<LvUi::MenuView>(&mainPresenter);
    // mainPresenter.subscribe(menuTab);
    // menuTab->init();

    // // ECG tab.
    // auto ecgTab = std::make_shared<LvUi::EcgView>(&mainPresenter);
    // mainPresenter.subscribe(ecgTab);
    // ecgTab->init();

    // // Oxygen tab view.
    // auto oxygenTab = std::make_shared<LvUi::OxygenView>(&mainPresenter);
    // mainPresenter.subscribe(oxygenTab);
    // oxygenTab->init();

    lv_disp_load_scr(active_screen);

    while(1) {
      lv_timer_handler();
      usleep(5 * 1000);
    }

    return 0;
}


// Initialize the Hardware Abstraction Layer (HAL).
static lv_display_t * hal_init(int32_t w, int32_t h)
{
  lv_group_set_default(lv_group_create());

  lv_display_t* disp = lv_sdl_window_create(w, h);

  lv_indev_t* mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_display(mouse, disp);
  lv_display_set_default(disp);

  LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t* cursor_obj;
  cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
  lv_image_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

  lv_indev_t* mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_display(mousewheel, disp);
  lv_indev_set_group(mousewheel, lv_group_get_default());

  lv_indev_t* kb = lv_sdl_keyboard_create();
  lv_indev_set_display(kb, disp);
  lv_indev_set_group(kb, lv_group_get_default());

  return disp;
}
