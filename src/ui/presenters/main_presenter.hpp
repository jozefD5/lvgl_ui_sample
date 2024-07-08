#pragma once
#include "lvgl/lvgl.h"
#include "models/main_model.hpp"
#include "mvp/interfaces/base_pub_sub.hpp"



namespace LvUi {

    class MainPresenter : public BaseMvp::BasePublisher<LvUi::MainModel> {

        public:
            MainPresenter() : BaseMvp::BasePublisher<MainModel>(){}

    };


}
