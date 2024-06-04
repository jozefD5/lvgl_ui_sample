#include <iostream>
#include "ecg_model.h"

namespace LvUi {

    // Constructor.
    EcgModel::EcgModel(int32_t view_width, int32_t view_height): m_view_width(view_width), m_view_height(view_height) {
        m_ecg_demo_enabled = false;
    }


}
