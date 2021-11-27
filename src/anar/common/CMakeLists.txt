cmake_minimum_required(VERSION 3.5)

project(AnarCommon)

set(
        ANAR_SOURCES

        src/controller.cpp
        src/common-controller.cpp

        src/i-database.cpp
        src/database-factory.cpp
        src/mysql-database.cpp
        src/s-database.cpp

        src/a-jsonable.cpp

        src/service.cpp
        src/json-parser.cpp
        src/a-from-json-visitor.cpp
        src/binary.cpp
        src/printer.cpp
        src/string.cpp
        src/serial-port.cpp
        src/a-to-json-visitor.cpp
        src/exception.cpp
        src/i-visitor.cpp
)

add_library(
        AnarCommon
        SHARED
        ${ANAR_SOURCES}
)
add_library(
        Anar::Common
        ALIAS
        AnarCommon
)
set_target_properties(
        AnarCommon
        PROPERTIES
        VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
        OUTPUT_NAME AnarCommon
        DEFINE_SYMBOL Common_EXPORTS
)
target_include_directories(
        AnarCommon
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(
        AnarCommon
        PUBLIC
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
        ${PARS_PARK_MYSQL_LIB}
        ${PARS_PARK_POCO_FOUNDATION_LIB}
        ${PARS_PARK_LIMEREPORT_LIB}
        ${PARS_PARK_NLOHMANN_JSON_LIB}
        ${PARS_PARK_ODB_LIB}
        ${PARS_PARK_ODB_MYSQL_LIB}
        ${PARS_PARK_OATPP_LIB}
        ${PARS_PARK_SERIAL_LIB}
        ${PARS_PARK_GOOGLE_LOG_LIB}
        ${PARS_PARK_GOOGLE_TEST_LIB}
)