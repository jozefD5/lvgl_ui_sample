#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"

namespace LvUi {
    /*******************************************************************************
     * @brief  Main navigation bottom bar view.
     *
     ******************************************************************************/
    class MainTabView : public BaseMvp::IBaseView{

        private:
            lv_obj_t *m_tab_view;           // Tab view.
            lv_obj_t *m_tab_main_menu;      // Main menu tab.
            lv_obj_t *m_tab_ecg;            // ECG tab.
            lv_obj_t *m_tab_oxygen;         // Oxygen tab.

        public:

            /*******************************************************************************
             * @brief Construct UI.
             *
             * @param parent_widget pointer to parent widget
             *
             ******************************************************************************/
            void create(lv_obj_t *parent_widget);

            /*******************************************************************************
             * @brief Get the Main Tab object
             *
             * @return lv_obj_t* pointer to main tab view.
             ******************************************************************************/
            lv_obj_t * getMainTab(void);

            /*******************************************************************************
             * @brief Get the ECG Tab object
             *
             * @return lv_obj_t* pointer to ECG tab view.
             ******************************************************************************/
            lv_obj_t * getEcgTab(void);

            /*******************************************************************************
             * @brief Get the oxygen Tab object
             *
             * @return lv_obj_t* pointer to oxygen tab view.
             ******************************************************************************/
            lv_obj_t * getOxygenTab(void);

            void notifyView(const BaseMvp::IBaseNotificationEvent* p) override;
    };

}
