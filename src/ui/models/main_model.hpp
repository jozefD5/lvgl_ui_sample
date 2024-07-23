#pragma once
#include <string>
#include <vector>
#include "lvgl/lvgl.h"

namespace LvUi {
    /*******************************************************************************
     * @brief Temperature units enum.
     *
     ******************************************************************************/
    enum class TemperatureUnit{
        Celsius,
        Fahrenheit
    };


    /*******************************************************************************
     * @brief Main application model, holds key application data that are shared
     *        between multiple views.
     *
     ******************************************************************************/
    class MainModel {
        private:
            std::vector<std::string> temperatureUintsSufix;

        public:
            // Chart series.
            lv_chart_series_t ecgDataSerias;
            lv_chart_series_t heartRateDataSerias;
            lv_chart_series_t oxygenDataSerias;
            lv_chart_series_t temperatureDataSerias;

            // Temperature settings.
            TemperatureUnit temperatureUnit;
            std::string temperatureSufix;

            MainModel();

            std::string getTemperatureSufix(uint8_t index);
    };
}
