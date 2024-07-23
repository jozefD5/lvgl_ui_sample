#include <iostream>
#include "main_model.hpp"

namespace LvUi {
    MainModel::MainModel()
    {
        temperatureUintsSufix.insert(
            temperatureUintsSufix.end(),
            {"Celsius", "Fahrenheit"}
        );

        temperatureUnit = TemperatureUnit::Celsius;
        temperatureSufix = temperatureUintsSufix[0];
    }

    std::string MainModel::getTemperatureSufix(uint8_t index)
    {
        if(index >= temperatureUintsSufix.size() | index < 0) {
            return "";
        } else {
            return temperatureUintsSufix[index];
        }
    }
}
