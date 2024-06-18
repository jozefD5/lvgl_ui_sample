#include <iostream>
#include "ecg_view.h"

// namespace LvUi {

//     void EcgView::switch_event_callback(lv_event_t *e)
//     {
//         void* void_ptr = lv_event_get_user_data(e);
//         EcgView* view_ptr = static_cast<EcgView *>(void_ptr);

//         // LVGL will call callback before changing state, therfore state
//         // is always previous state.
//         bool sw_state = !lv_obj_has_state(view_ptr->m_ecg_switch, LV_STATE_CHECKED);

//         NEcgSetSwitchState event = NEcgSetSwitchState(sw_state);
//         view_ptr->notifyPublisher(&event);
//     }

//     EcgView::EcgView(IBasePublisher *publisher)
//     {
//         m_publisher = publisher;
//         m_model_ = static_cast<MainModel *>(m_publisher->getModel());
//     }

//     void EcgView::init(void)
//     {
//         auto active_view = m_model_->m_ecg_tab;

//         lv_obj_t* ui_ecgTitleLabel = lv_label_create(active_view);
//         lv_obj_set_width(ui_ecgTitleLabel, LV_SIZE_CONTENT);
//         lv_obj_set_height(ui_ecgTitleLabel, LV_SIZE_CONTENT);
//         lv_obj_set_x(ui_ecgTitleLabel, 0);
//         lv_obj_set_y(ui_ecgTitleLabel, -190);
//         lv_obj_set_align(ui_ecgTitleLabel, LV_ALIGN_CENTER);
//         lv_label_set_text(ui_ecgTitleLabel, "ECG");
//         lv_obj_set_style_text_color(ui_ecgTitleLabel, lv_color_hex(0x1526E0), LV_STATE_DEFAULT);
//         lv_obj_set_style_text_opa(ui_ecgTitleLabel, 255, LV_STATE_DEFAULT);
//         lv_obj_set_style_text_letter_space(ui_ecgTitleLabel, 5, LV_STATE_DEFAULT);
//         lv_obj_set_style_text_line_space(ui_ecgTitleLabel, 0, LV_STATE_DEFAULT);
//         lv_obj_set_style_text_font(ui_ecgTitleLabel, &lv_font_montserrat_28, LV_STATE_DEFAULT);

//         m_model_->m_ecg_chart = lv_chart_create(active_view);
//         lv_obj_set_width(m_model_->m_ecg_chart, lv_pct(90));
//         lv_obj_set_height(m_model_->m_ecg_chart, lv_pct(80));
//         lv_obj_set_x(m_model_->m_ecg_chart, 0);
//         lv_obj_set_y(m_model_->m_ecg_chart, 20);
//         lv_obj_set_align(m_model_->m_ecg_chart, LV_ALIGN_CENTER);
//         lv_obj_add_flag(m_model_->m_ecg_chart, LV_OBJ_FLAG_OVERFLOW_VISIBLE);      //make scales visible - Should it be forced to True?

//         lv_chart_set_point_count(m_model_->m_ecg_chart, 40);
//         lv_chart_set_div_line_count(m_model_->m_ecg_chart, 5, 10);

//         lv_obj_t* ui_ecgChart_Xaxis = lv_scale_create(m_model_->m_ecg_chart);
//         lv_scale_set_mode(ui_ecgChart_Xaxis, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
//         lv_obj_set_size(ui_ecgChart_Xaxis, lv_pct(100), 50);
//         lv_obj_set_align(ui_ecgChart_Xaxis, LV_ALIGN_BOTTOM_MID);
//         lv_obj_set_y(ui_ecgChart_Xaxis, 50 + lv_obj_get_style_pad_bottom(m_model_->m_ecg_chart,
//                                                                         LV_PART_MAIN) + lv_obj_get_style_border_width(m_model_->m_ecg_chart, LV_PART_MAIN));
//         lv_obj_set_style_line_width(ui_ecgChart_Xaxis, 0, LV_PART_MAIN);
//         lv_obj_set_style_line_width(ui_ecgChart_Xaxis, 1, LV_PART_ITEMS);   //LVGL-9.1 ticks are thicker by default
//         lv_obj_set_style_line_width(ui_ecgChart_Xaxis, 1, LV_PART_INDICATOR);
//         lv_obj_set_style_length(ui_ecgChart_Xaxis, 5, LV_PART_ITEMS);      //minor tick length
//         lv_obj_set_style_length(ui_ecgChart_Xaxis, 10, LV_PART_INDICATOR);      //major tick length
//         lv_scale_set_range(ui_ecgChart_Xaxis, 0, 5 > 0 ? 5 - 1 : 0);
//         lv_scale_set_total_tick_count(ui_ecgChart_Xaxis, (5 > 0 ? 5 - 1 : 0) * 2 + 1);
//         lv_scale_set_major_tick_every(ui_ecgChart_Xaxis, 2 >= 1 ? 2 : 1);
//         lv_obj_t* ui_ecgChart_Yaxis1 = lv_scale_create(m_model_->m_ecg_chart);
//         lv_scale_set_mode(ui_ecgChart_Yaxis1, LV_SCALE_MODE_VERTICAL_LEFT);
//         lv_obj_set_size(ui_ecgChart_Yaxis1, 50, lv_pct(100));
//         lv_obj_set_align(ui_ecgChart_Yaxis1, LV_ALIGN_LEFT_MID);
//         lv_obj_set_x(ui_ecgChart_Yaxis1, -50 - lv_obj_get_style_pad_left(m_model_->m_ecg_chart,
//                                                                         LV_PART_MAIN) - lv_obj_get_style_border_width(m_model_->m_ecg_chart, LV_PART_MAIN) + 2);
//         lv_obj_set_style_line_width(ui_ecgChart_Yaxis1, 0, LV_PART_MAIN);
//         lv_obj_set_style_line_width(ui_ecgChart_Yaxis1, 1, LV_PART_ITEMS);
//         lv_obj_set_style_line_width(ui_ecgChart_Yaxis1, 1, LV_PART_INDICATOR);
//         lv_obj_set_style_length(ui_ecgChart_Yaxis1, 5, LV_PART_ITEMS);   //minor tick length
//         lv_obj_set_style_length(ui_ecgChart_Yaxis1, 10, LV_PART_INDICATOR);   //major tick length
//         lv_scale_set_total_tick_count(ui_ecgChart_Yaxis1, (5 > 0 ? 5 - 1 : 0) * 2 + 1);
//         lv_scale_set_major_tick_every(ui_ecgChart_Yaxis1, 2 >= 1 ? 2 : 1);
//         lv_obj_t* ui_ecgChart_Yaxis2 = lv_scale_create(m_model_->m_ecg_chart);
//         lv_scale_set_mode(ui_ecgChart_Yaxis2, LV_SCALE_MODE_VERTICAL_RIGHT);
//         lv_obj_set_size(ui_ecgChart_Yaxis2, 25, lv_pct(100));
//         lv_obj_set_align(ui_ecgChart_Yaxis2, LV_ALIGN_RIGHT_MID);
//         lv_obj_set_x(ui_ecgChart_Yaxis2, 25 + lv_obj_get_style_pad_right(m_model_->m_ecg_chart,
//                                                                         LV_PART_MAIN) + lv_obj_get_style_border_width(m_model_->m_ecg_chart, LV_PART_MAIN) + 1);
//         lv_obj_set_style_line_width(ui_ecgChart_Yaxis2, 0, LV_PART_MAIN);
//         lv_obj_set_style_line_width(ui_ecgChart_Yaxis2, 1, LV_PART_ITEMS);
//         lv_obj_set_style_line_width(ui_ecgChart_Yaxis2, 1, LV_PART_INDICATOR);
//         lv_obj_set_style_length(ui_ecgChart_Yaxis2, 5, LV_PART_ITEMS);   //minor tick length
//         lv_obj_set_style_length(ui_ecgChart_Yaxis2, 10, LV_PART_INDICATOR);   //major tick length
//         lv_scale_set_total_tick_count(ui_ecgChart_Yaxis2, (5 > 0 ? 5 - 1 : 0) * 2 + 1);
//         lv_scale_set_major_tick_every(ui_ecgChart_Yaxis2, 2 >= 1 ? 2 : 1);
//         m_model_->m_ecg_chart_series = lv_chart_add_series(m_model_->m_ecg_chart, lv_color_hex(0xDA1905), LV_CHART_AXIS_PRIMARY_Y);

//         //This workaround (an invisible outline) is needed because without it chart overflow-visible doesn't work in LVGL-9.1
//         lv_obj_set_style_outline_pad(m_model_->m_ecg_chart, LV_MAX3(50, 50, 25), LV_STATE_DEFAULT);   //workaround for ineffective 'overflow visible' flag
//         lv_obj_set_style_outline_width(m_model_->m_ecg_chart, -1, LV_STATE_DEFAULT);

//         m_ecg_switch = lv_switch_create(active_view);
//         lv_obj_set_width(m_ecg_switch, 62);
//         lv_obj_set_height(m_ecg_switch, 31);
//         lv_obj_set_x(m_ecg_switch, 351);
//         lv_obj_set_y(m_ecg_switch, -190);
//         lv_obj_set_align(m_ecg_switch, LV_ALIGN_CENTER);
//         lv_obj_set_style_bg_color(m_ecg_switch, lv_color_hex(0xDE0C0C), LV_STATE_DEFAULT);
//         lv_obj_set_style_bg_opa(m_ecg_switch, 255, LV_STATE_DEFAULT);

//         lv_obj_add_event_cb(m_ecg_switch, switch_event_callback, LV_EVENT_PRESSED, this);
//     }
// }
