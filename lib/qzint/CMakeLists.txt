cmake_minimum_required(VERSION 3.17)

project(${ANAR_QZINT_LIB})

find_package(Qt5Widgets)
find_package(Qt5Gui)

include_directories(BEFORE "${ANAR_ZINT_DIR}")

set(QZint_SRCS qzint.cpp)

add_library(${PROJECT_NAME} SHARED ${QZint_SRCS})

add_dependencies(${PROJECT_NAME} ${ANAR_ZINT_LIB})

target_link_libraries(${PROJECT_NAME} ${ANAR_ZINT_LIB} Qt5::Widgets Qt5::Gui)
