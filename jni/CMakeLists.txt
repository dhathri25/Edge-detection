cmake_minimum_required(VERSION 3.4.1)

add_library(native_processor SHARED native_processor.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(native_processor ${OpenCV_LIBS})
