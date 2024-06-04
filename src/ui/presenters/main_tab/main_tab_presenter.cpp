#include <iostream>
#include "main_tab_presenter.h"
#include "lvgl/lvgl.h"
#include "mvp/interfaces/i_base_mvp.h"


namespace LvUi {

    LvUi::MainTabPresenter::MainTabPresenter(MainTabView *view, lv_obj_t *parent_widget) : m_view(view)
    {
        m_view->setSubscriber(this);
        m_view->create(parent_widget);
    }

    void MainTabPresenter::notifyPresenter(const BaseMvp::IBaseNotificationEvent *p)
    {
    }

}
