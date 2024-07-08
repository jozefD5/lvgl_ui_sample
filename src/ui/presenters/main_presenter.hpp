#pragma once
#include "lvgl/lvgl.h"
#include "models/main_model.hpp"
#include "mvp/interfaces/publisher/base_publisher.hpp"



namespace LvUi {

    class MainPresenter : public BaseMvp::BasePresenter<LvUi::MainModel> {

        public:
            MainPresenter() : BaseMvp::BasePresenter<MainModel>(){}

    };


}
