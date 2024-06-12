#pragma once
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"

using namespace BaseMvp;

namespace LvUi {
    class MainPresenter : public IBasePublisher{
        public:
            MainModel *m_dataModel_;

        public:
            MainPresenter(MainModel *dataModel);

            void onSubscriberData(IBaseNotificationType type) override;

            void* getModel(void) override;
    };
}
