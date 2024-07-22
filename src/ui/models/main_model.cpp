#include <iostream>
#include "main_model.hpp"

namespace LvUi {
    MainModel::MainModel()
    {
        temperatureUintsSufix = {"Celsius", "Fahrenheit"};
        temperatureUnit = TemperatureUnit::Celsius;
        temperatureSufix = temperatureUintsSufix[0];
    }
}
