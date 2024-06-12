#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"

using namespace BaseMvp;

namespace LvUi {

    /*******************************************************************************
     * @brief Notification to set ECG switch state.
     *
     ******************************************************************************/
    class NEcgSetSwitchState : public IBaseNotificationType{
        public:
            int m_state;

        NEcgSetSwitchState(int state): m_state(state) {
            m_notification_type = 0;
        }
    };

    /*******************************************************************************
     * @brief Notification to set oxygen switch state.
     *
     ******************************************************************************/
    class NOxygenSetSwitchState : public IBaseNotificationType{
        public:
            int m_state;

        NOxygenSetSwitchState(int state): m_state(state) {
            m_notification_type = 1;
        }
    };

}
