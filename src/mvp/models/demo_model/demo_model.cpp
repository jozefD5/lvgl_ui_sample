#include <iostream>
#include "demo_model.h"

namespace LvUi {

    // Constructor.
    DemoModel::DemoModel(int val1, int val2): demo_value_1(val1), demo_value_2(val2) {}


    void DemoModel::setValue1(int val) {
        this->demo_value_1 = val;
    }

    void DemoModel::setValue2(int val) {
        this->demo_value_2 = val;
    }

    int DemoModel::getValue1() {
        return this->demo_value_1;
    }

    int DemoModel::getValue2() {
        return this->demo_value_2;
    }

}
