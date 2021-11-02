cmake_minimum_required(VERSION 3.5)

project(Anar)

file(STRINGS "${PROJECT_SOURCE_DIR}/libversion" SHARED_LIBRARY_VERSION)
# Read the version information from the VERSION file
file(STRINGS "${PROJECT_SOURCE_DIR}/VERSION" PACKAGE_VERSION)
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" CPACK_PACKAGE_VERSION_MAJOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1" CPACK_PACKAGE_VERSION_MINOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" CPACK_PACKAGE_VERSION_PATCH ${PACKAGE_VERSION})

set(PROJECT_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

configure_file("config.hpp.in" "config.hpp")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory("model")
add_subdirectory("const")
add_subdirectory("controller")
add_subdirectory("database")
add_subdirectory("exception")
add_subdirectory("interface")
add_subdirectory("log")
add_subdirectory("service")
add_subdirectory("task")