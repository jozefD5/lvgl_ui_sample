file(GLOB_RECURSE mpv_source_list
    "*.cpp"
    "*.hpp"
    "*.c"
    "*.h"
)


add_library(ui_module STATIC
    ${mpv_source_list}
)

target_include_directories(ui_module PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
