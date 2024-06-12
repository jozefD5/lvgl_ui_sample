#include <iostream>
#include "main_presenter.h"
#include "lvgl/lvgl.h"
#include "mvp/interfaces/base_pub_sub.h"

namespace LvUi {

    MainPresenter::MainPresenter(MainModel *dataModel) : m_dataModel_(dataModel) {}

    void MainPresenter::onSubscriberData(IBaseNotificationType type)
    {
    }

    void *MainPresenter::getModel(void)
    {
        return m_dataModel_;
    }
}
