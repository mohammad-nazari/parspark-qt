cmake_minimum_required(VERSION 3.16)

project(AnarParsParkUnitTest)

set(
        TEST_SOURCES
        main.cpp
)

add_executable(
        ${PROJECT_NAME}
        ${TEST_SOURCES}
)

target_link_libraries(
        ${PROJECT_NAME}
        gtest
)