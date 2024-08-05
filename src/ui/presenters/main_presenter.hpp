#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <random>
#include "lvgl/lvgl.h"
#include "models/main_model.hpp"
#include "mvp/interfaces/base_pub_sub.hpp"


namespace LvUi {

    /*******************************************************************************
     * @brief Main presenter events enum, includes all events main presenter
     *        can handle.
     *
     ******************************************************************************/
    typedef enum {
        UpdateTemperatureUnit = 0,

    } MainPresenterEvent;



    /*******************************************************************************
     * @brief Main presenter, handles core and shared business logic across
     *        multiple UI views
     *
     ******************************************************************************/
    class MainPresenter : public BaseMvp::BasePublisher<LvUi::MainModel> {
        public:
            MainPresenter() : BaseMvp::BasePublisher<MainModel>(){

                // Register events.
                registerEvent(
                    BaseMvp::BaseEvent(UpdateTemperatureUnit),
                    std::bind(&MainPresenter::updateTemperatureUnit, this, std::placeholders::_1)
                );
            }

        private:
            /*******************************************************************************
             * @brief Update temperature unit. available units are celsius
             *        and fahrenheit.
             *
             * @param data temperature unit, needs to be of type
             *        const TemperatureUnit*
             *
             ******************************************************************************/
            void updateTemperatureUnit(const void *data) {
                const TemperatureUnit *temperatureUnit = (TemperatureUnit*)data;

                getModel()->temperatureUnit = *temperatureUnit;

                if(*temperatureUnit == LvUi::TemperatureUnit::Celsius) {
                    getModel()->temperatureSufix = getModel()->getTemperatureSufix(0);
                } else {
                    getModel()->temperatureSufix = getModel()->getTemperatureSufix(1);
                }

                std::cout << "Update temperature unit: " << getModel()->temperatureSufix << std::endl;
            }

    };

}
