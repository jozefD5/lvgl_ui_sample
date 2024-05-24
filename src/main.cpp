#define _DEFAULT_SOURCE /* needed for usleep() */
#include <iostream>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "views/main_view/main_view.h"
#include "presenters/main_presenter/main_presenter.h"


/*******************************************************************************
 * Function prototype
 ******************************************************************************/
static lv_display_t * hal_init(int32_t w, int32_t h);


/*******************************************************************************
 * Private Static variables
 ******************************************************************************/





int main(int argc, char **argv) {
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init(1280, 720);

    // Main view.
    LvUi::MainView mainView;
    LvUi::DemoModel demoModel(0, 0);

    LvUi::MainPresenter mainPresenter(&mainView, &demoModel);

    while(1) {
      lv_timer_handler();
      usleep(5 * 1000);
    }

    return 0;
}



/*******************************************************************************
 * @brief Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 *        library
 *
 * @param w  display width in pixels
 * @param h  display height in pixels
 *
 * @return lv_display_t* pointer to structure representing display.
 ******************************************************************************/
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
