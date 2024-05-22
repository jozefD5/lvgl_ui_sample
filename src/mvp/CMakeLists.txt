file(GLOB_RECURSE mpv_source_list
    "*.cpp"
    "*.hpp"
    "*.c"
    "*.h"
)


add_library(mpv STATIC
    ${mpv_source_list}
)

target_include_directories(mpv PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
