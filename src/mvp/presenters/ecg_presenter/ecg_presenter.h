#pragma once
#include <models/ecg_model/ecg_model.h>
#include "lvgl/lvgl.h"
#include "views/ecg_view/ecg_view.h"

namespace LvUi {

    class EcgPresenter : public IBasePresenter{
        private:
            EcgView* view;              // View (UI)
            EcgModel* ecgModel;        // Data model for this view.

        public:
            EcgPresenter(EcgView* view, EcgModel* EcgModel);

            void updateAllValues(int val1, int val2);

            void notifyPresenter(void* p) override;
    };

}
