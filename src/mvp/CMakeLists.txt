file(GLOB_RECURSE mpv_source_list
    "*.cpp"
    "*.hpp"
    "*.c"
    "*.h"
)


add_library(mpv_base STATIC
    ${mpv_source_list}
)

target_include_directories(mpv_base PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
