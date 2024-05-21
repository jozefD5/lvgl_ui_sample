cmake_minimum_required(VERSION 3.10)
project(lvgl_ui_demo)

# Set C and C++ standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# Set binary outputh path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)


add_executable(lvgl_ui_demo src/main.cpp  src/main.h)
