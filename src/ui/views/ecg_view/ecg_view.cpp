#include <iostream>
#include "ecg_view.hpp"

namespace LvUi {
    EcgView::EcgView(BaseMvp::BasePublisher<LvUi::MainModel> *mainPublisher)
        : mainPublisher_(mainPublisher)
    {
        std::cout << "ID: " << mainPublisher_->getId() << std::endl;
        mainPublisher_->subscribe(mainSubscriber_);
    }
}
