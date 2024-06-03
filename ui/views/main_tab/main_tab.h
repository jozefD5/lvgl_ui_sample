#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"

namespace LvUi {

    class MainTabView : public BaseMvp::IBaseView {
        private:




        public:
            MainTabView();
            ~MainTabView();

            void notifyView(const BaseMvp::IBaseNotificationEvent* p) override;

            void create(void);

    };

}
