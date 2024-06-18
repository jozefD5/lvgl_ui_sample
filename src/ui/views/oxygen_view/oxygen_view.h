#pragma once
#include "mvp/interfaces/base_pub_sub.h"
#include "models/main_model.h"
#include "presenters/main_presenter.h"
#include "lvgl/lvgl.h"

using namespace BaseMvp;

// namespace LvUi {

//     /*******************************************************************************
//      * @brief Oxygen data view.
//      *
//      ******************************************************************************/
//     class OxygenView : public IBaseSubscriber {
//         public:
//             MainModel *m_model_;          // Pointer to presenter's model (data).
//             lv_obj_t *m_oxygen_switch;    // ECG enable/disable switch.

//         private:
//             /*******************************************************************************
//              * @brief Static function used as call back for switch.
//              *
//              ******************************************************************************/
//             static void switch_event_callback(lv_event_t *e);

//         public:
//             /*******************************************************************************
//              * @brief Construct a new Oxygen View object
//              *
//              * @param publisher pointer to publisher for bi-directional communication.
//              *
//              ******************************************************************************/
//             OxygenView(IBasePublisher *publisher);

//             /*******************************************************************************
//              * @brief Initialise core components and create UI.
//              *
//              ******************************************************************************/
//             void init(void);
//     };

// }
