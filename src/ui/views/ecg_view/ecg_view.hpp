#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.hpp"
#include "models/main_model.hpp"
#include "presenters/main_presenter.hpp"

namespace LvUi {

    class EcgView {
        private:
            // Main presenter.
            BaseMvp::BasePublisher<LvUi::MainModel>* mainPublisher_;
            std::shared_ptr<BaseMvp::BaseSubscriber> mainSubscriber_;

        public:
            EcgView(BaseMvp::BasePublisher<LvUi::MainModel>* mainPublisher);

            void view() {

            }


    };


}
