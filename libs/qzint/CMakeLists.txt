cmake_minimum_required(VERSION 3.17)

project(qzint)

find_package(Qt5Widgets)
find_package(Qt5Gui)

set(QZint_SRCS qzint.cpp)

add_library(${PROJECT_NAME} SHARED ${QZint_SRCS})

add_dependencies(${PROJECT_NAME} zint)

target_link_libraries(${PROJECT_NAME} zint Qt6::Widgets Qt6::Gui)
