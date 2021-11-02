cmake_minimum_required(VERSION 3.5)

project(ParsPark)

file(STRINGS "${PROJECT_SOURCE_DIR}/libversion" SHARED_LIBRARY_VERSION)
# Read the version information from the VERSION file
file(STRINGS "${PROJECT_SOURCE_DIR}/VERSION" PACKAGE_VERSION)
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" CPACK_PACKAGE_VERSION_MAJOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1" CPACK_PACKAGE_VERSION_MINOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" CPACK_PACKAGE_VERSION_PATCH ${PACKAGE_VERSION})

set(PROJECT_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

configure_file("config.hpp.in" "config.hpp")

add_definitions(-DDATABASE_MYSQL)

option(DEPLOYMENT "In development state show console for debug and see warnings and other console data" OFF)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(DONT_SHOW_CONSOLE WIN32)
    endif ()
endif ()

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(
        Qt5
        COMPONENTS
        Core
        LinguistTools
        Qml
        Quick
        REQUIRED
)

set(
        TS_FILES
        "locale/ParsPark_fa_IR.ts"
)

message("${PARS_PARK_MESSAGE} ${TS_FILES}")

set(
        PARS_PARK_SOURCES

        ${CMAKE_SOURCE_DIR}/resource/rc/icon.rc
        ${CMAKE_SOURCE_DIR}/resource/qrc/qml.qrc

        service/qt-std-converter.cpp
        service/s-settings.cpp
        service/model-binding/database/mysql/contact-model-odb.cxx
        service/model-binding/database/mysql/person-model-odb.cxx
        service/model-binding/database/mysql/user-model-odb.cxx
        service/model-binding/database/mysql/create-modify-delete-model-odb.cxx
        service/model-binding/database/mysql/card-model-odb.cxx
        service/model-binding/database/mysql/car-model-odb.cxx
        service/model-binding/database/mysql/black-list-model-odb.cxx
        service/model-binding/database/mysql/contact-model-odb.cxx
        service/model-binding/database/mysql/driver-model-odb.cxx
        service/model-binding/database/mysql/lost-card-model-odb.cxx
        service/model-binding/database/mysql/organization-model-odb.cxx
        service/model-binding/database/mysql/parking-log-model-odb.cxx
        service/model-binding/database/mysql/subscription-model-odb.cxx

        view/view.cpp
        view/common-view.cpp
        view/login/login-view.cpp
        view/settings/settings-view.cpp
        view/s-view.cpp

        controller/login-controller.cpp
        controller/settings-controller.cpp
        nazari-test.cpp
)

set(
        PARS_PARK_TEST_SOURCES
)

if (WIN32)
    add_executable(
            ${PROJECT_NAME}
            ${DONT_SHOW_CONSOLE}
            main.cpp
            ${PARS_PARK_SOURCES}
    )
#    add_executable(
#            ${PROJECT_NAME}_Unit_Test
#            ${DONT_SHOW_CONSOLE}
#            ${PARS_PARK_SOURCES}
#            ${PARS_PARK_TEST_SOURCES}
#            test/main.cpp
#    )
else ()
    add_executable(
            ${PROJECT_NAME}
            ${PARS_PARK_SOURCES}
            main.cpp
    )
#    add_executable(
#            ${PROJECT_NAME}_Unit_Test
#            ${PARS_PARK_SOURCES}
#            ${PARS_PARK_TEST_SOURCES}
#            test/main.cpp
#    )
endif ()

target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>:QT_QML_DEBUG>
)
#target_compile_definitions(
#        ${PROJECT_NAME}_Unit_Test
#        PRIVATE
#        $<$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>:QT_QML_DEBUG>
#)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
        ${PARS_PARK_MYSQL_LIB}
        ${PARS_PARK_POCO_FOUNDATION_LIB}
        ${PARS_PARK_POCO_DATA_LIB}
        ${PARS_PARK_POCO_DATA_MYSQL_LIB}
        ${PARS_PARK_POCO_DATA_SQLITE_LIB}
        ${PARS_PARK_LIMEREPORT_LIB}
#        ${PARS_PARK_NLOHMANN_JSON_LIB}
        ${PARS_PARK_ODB_LIB}
        ${PARS_PARK_ODB_MYSQL_LIB}
        ${PARS_PARK_OATPP_LIB}
        ${PARS_PARK_SERIAL_LIB}
        ${PARS_PARK_GOOGLE_LOG_LIB}
        ${PARS_PARK_GOOGLE_TEST_LIB}
#        ${PARS_PARK_ANAR_CONST_LIB}
        ${PARS_PARK_ANAR_CONTROLLER_LIB}
        ${PARS_PARK_ANAR_DATABASE_LIB}
#        ${PARS_PARK_ANAR_EXCEPTION_LIB}
        ${PARS_PARK_ANAR_INTERFACE_LIB}
#        ${PARS_PARK_ANAR_LOG_LIB}
#        ${PARS_PARK_ANAR_MODEL_LIB}
        ${PARS_PARK_ANAR_SERVICE_LIB}
#        ${PARS_PARK_ANAR_TASK_LIB}
)
#target_link_libraries(
#        ${PROJECT_NAME}_Unit_Test
#        Qt5::Core
#        Qt5::Qml
#        Qt5::Quick
#        ${PARS_PARK_MYSQL_LIB}
#        ${PARS_PARK_POCO_FOUNDATION_LIB}
#        ${PARS_PARK_POCO_DATA_LIB}
#        ${PARS_PARK_POCO_DATA_MYSQL_LIB}
#        ${PARS_PARK_POCO_DATA_SQLITE_LIB}
#        ${PARS_PARK_LIMEREPORT_LIB}
#        ${PARS_PARK_NLOHMANN_JSON_LIB}
#        ${PARS_PARK_ODB_LIB}
#        ${PARS_PARK_ODB_MYSQL_LIB}
#        ${PARS_PARK_OATPP_LIB}
#        ${PARS_PARK_SERIAL_LIB}
#        ${PARS_PARK_GOOGLE_LOG_LIB}
#        ${PARS_PARK_GOOGLE_TEST_LIB}
#        ${PARS_PARK_ANAR_CONST_LIB}
#        ${PARS_PARK_ANAR_CONTROLLER_LIB}
#        ${PARS_PARK_ANAR_DATABASE_LIB}
#        ${PARS_PARK_ANAR_EXCEPTION_LIB}
#        ${PARS_PARK_ANAR_INTERFACE_LIB}
#        ${PARS_PARK_ANAR_LOG_LIB}
#        ${PARS_PARK_ANAR_MODEL_LIB}
#        ${PARS_PARK_ANAR_SERVICE_LIB}
#        ${PARS_PARK_ANAR_TASK_LIB}
#)

qt5_create_translation(
        QM_FILES
        ${TS_FILES}
)
set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
        OUTPUT_NAME Anar${PROJECT_NAME}
        DEFINE_SYMBOL ${PROJECT_NAME}_EXPORTS
)

#d:\Tools\ODB\odb-compiler\bin\odb.exe -d mysql --generate-query --generate-schema --std c++11 person.hxx
#d:\Tools\ODB\odb-compiler\bin\odb.exe --std c++11 --database mysql --generate-schema --generate-query --hxx-prologue "#include \"traits.hxx\""  --table-prefix mapping_ person.hxx