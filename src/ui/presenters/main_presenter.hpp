#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <random>
#include "lvgl/lvgl.h"
#include "models/main_model.hpp"
#include "mvp/interfaces/base_pub_sub.hpp"



namespace LvUi {

    typedef enum {
        UpdateTemperatureUnit = 0,

    } MainPresenterEvent;






    class MainPresenter : public BaseMvp::BasePublisher<LvUi::MainModel> {


        private:
            void updateTemperatureUnit(void *data) {
                // getModel()->temperatureUnit = temperatureUnit;

                // if(temperatureUnit == LvUi::TemperatureUnit::Celsius) {
                //     getModel()->temperatureSufix = getModel()->getTemperatureSufix(0);
                // } else {
                //     getModel()->temperatureSufix = getModel()->getTemperatureSufix(1);
                // }

                // std::cout << "Update temperature unit: "
                //     << getModel()->temperatureSufix << std::endl;
            }


        public:
            MainPresenter() : BaseMvp::BasePublisher<MainModel>(){


                registerEvent(
                    BaseMvp::BaseEvent(UpdateTemperatureUnit),
                    std::bind(&MainPresenter::updateTemperatureUnit, this, std::placeholders::_1)
                );
            }






    };


}
