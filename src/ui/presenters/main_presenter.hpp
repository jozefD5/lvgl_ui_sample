#pragma once
#include "lvgl/lvgl.h"
#include "models/main_model.hpp"
#include "mvp/interfaces/base_pub_sub.hpp"



namespace LvUi {

    class MainPresenter : public BaseMvp::BasePresenter<LvUi::MainModel> {

        public:
            MainPresenter() : BaseMvp::BasePresenter<MainModel>(){}

    };


}
