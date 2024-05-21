#define _DEFAULT_SOURCE /* needed for usleep() */
#include <iostream>
#include <unistd.h>
#include "lvgl/lvgl.h"


static lv_display_t * hal_init(int32_t w, int32_t h);

void main_tab_view(void);


int main(int argc, char **argv) {
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    std::cout << "UI Test"  << std::endl;


    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init(1280, 720);

    main_tab_view();

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


void main_tab_view(void)
{
  lv_obj_t* tab_view = lv_tabview_create(lv_scr_act());
  lv_tabview_set_tab_bar_position(tab_view, LV_DIR_BOTTOM);

  lv_obj_t* tab1 = lv_tabview_add_tab(tab_view, "tab 1");
  lv_obj_t* tab2 = lv_tabview_add_tab(tab_view, "tab 2");
  lv_obj_t* tab3 = lv_tabview_add_tab(tab_view, "tab 3");

  // Window.
  // lv_obj_t * win1 = lv_win_create(tab1);
  // lv_win_add_title(win1, "Main Menu");

  // Chart.
  lv_obj_t* chart = lv_chart_create(tab1);
  lv_obj_set_size(chart, 1000, 600);
  lv_obj_align(chart, LV_ALIGN_CENTER,0,0);
  lv_chart_set_type(chart, LV_CHART_TYPE_LINE);

  lv_chart_series_t* series1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
  lv_chart_set_next_value(chart, series1, 50);
  lv_chart_set_next_value(chart, series1, 100);
  lv_chart_set_next_value(chart, series1, 30);
  lv_chart_set_next_value(chart, series1, 70);
  lv_chart_set_next_value(chart, series1, 50);
  lv_chart_set_next_value(chart, series1, 100);
  lv_chart_set_next_value(chart, series1, 30);
  lv_chart_set_next_value(chart, series1, 70);
  lv_chart_set_next_value(chart, series1, 50);
  lv_chart_set_next_value(chart, series1, 100);
  lv_chart_set_next_value(chart, series1, 30);
  lv_chart_set_next_value(chart, series1, 70);
}
