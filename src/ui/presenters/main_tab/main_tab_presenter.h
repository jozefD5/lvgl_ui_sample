#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"

namespace LvUi {

    class MainTabPresenter : public BaseMvp::IBasePresenter {

        void notifyPresenter(const BaseMvp::IBaseNotificationEvent* p) override;

    };

}
