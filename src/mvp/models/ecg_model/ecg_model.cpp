#include <iostream>
#include "ecg_model.h"

namespace LvUi {

    // Constructor.
    EcgModel::EcgModel(int val1, int val2): demo_value_1(val1), demo_value_2(val2) {}


    void EcgModel::setValue1(int val) {
        this->demo_value_1 = val;
    }

    void EcgModel::setValue2(int val) {
        this->demo_value_2 = val;
    }

    int EcgModel::getValue1() {
        return this->demo_value_1;
    }

    int EcgModel::getValue2() {
        return this->demo_value_2;
    }

}
