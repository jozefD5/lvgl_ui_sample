cmake_minimum_required(VERSION 3.10)
project(lvgl_ui_demo)

# Set C and C++ standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# Set binary outputh path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

find_package(SDL2 REQUIRED SDL2)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/core
)

add_executable(${PROJECT_NAME} src/main.cpp  src/mouse_cursor_icon.c  src/main.h)
target_compile_definitions(${PROJECT_NAME} PRIVATE LV_CONF_INCLUDE_SIMPLE)
set(LV_CONF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lv_conf.h CACHE STRING "" FORCE)

add_subdirectory(lvgl)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/mvp)
target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    lvgl lvgl::thorvg
    m pthread
    mpv
)


if(LV_USE_DRAW_SDL)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
    # Need to install libsdl2-image-dev
    # `sudo apt install libsdl2-image-dev`
    # `brew install sdl2_image`
    find_package(SDL2_image REQUIRED)
    target_include_directories(lvgl PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
    target_link_libraries(main ${SDL2_IMAGE_LIBRARIES} CoreLib)
endif(LV_USE_DRAW_SDL)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(lvgl PRIVATE
        -pedantic-errors
        -Wall
        -Wclobbered
        -Wdeprecated
        -Wdouble-promotion
        -Wempty-body
        -Wextra
        -Wformat-security
        -Wmaybe-uninitialized
        # -Wmissing-prototypes
        -Wpointer-arith
        -Wmultichar
        -Wno-pedantic # ignored for now, we convert functions to pointers for propertis table.
        -Wreturn-type
        -Wshadow
        -Wshift-negative-value
        -Wsizeof-pointer-memaccess
        -Wtype-limits
        -Wundef
        -Wuninitialized
        -Wunreachable-code
        -Wfloat-conversion
        -Wstrict-aliasing
    )

    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,leak,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,leak,undefined)
endif()
