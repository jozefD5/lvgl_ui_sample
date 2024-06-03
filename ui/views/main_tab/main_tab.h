#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"

namespace LvUi {

    class MainTabView : public BaseMvp::IBaseView {


        public:
            void notifyView(const BaseMvp::IBaseNotificationEvent* p) override;

    };

}
