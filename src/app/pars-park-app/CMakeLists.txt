cmake_minimum_required(VERSION 3.5)

project(ParsPark)

file(STRINGS "${PROJECT_SOURCE_DIR}/libversion" SHARED_LIBRARY_VERSION)
# Read the version information from the VERSION file
file(STRINGS "${PROJECT_SOURCE_DIR}/VERSION" PACKAGE_VERSION)
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+\\.[0-9]+.*" "\\1" ANAR_PARS_PARK_PRODUCT_VERSION_MAJOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" ANAR_PARS_PARK_PRODUCT_VERSION_MINOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1" ANAR_PARS_PARK_PRODUCT_VERSION_PATCH ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.[0-9]+\\.([0-9]+.*)" "\\1" ANAR_PARS_PARK_PRODUCT_VERSION_REVISION ${PACKAGE_VERSION})

set(ANAR_PARS_PARK_PRODUCT_PROJECT_VERSION ${ANAR_PARS_PARK_PRODUCT_VERSION_MAJOR}.${ANAR_PARS_PARK_PRODUCT_VERSION_MINOR}.${ANAR_PARS_PARK_PRODUCT_VERSION_PATCH}.${ANAR_PARS_PARK_PRODUCT_VERSION_REVISION})
set(ANAR_PARS_PARK_PRODUCT_COMPANY_NAME "Anshan Rayanesh")
set(ANAR_PARS_PARK_PRODUCT_ICON "${CMAKE_SOURCE_DIR}/image/icon/Icon3.ico")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

if (WIN32)
    include(cmake/generate_product_version.cmake)
    generate_product_version(
            ProductAnarParsParkVersionFiles
            NAME ${PROJECT_NAME}
            VERSION_MAJOR ${ANAR_PARS_PARK_PRODUCT_VERSION_MAJOR}
            VERSION_MINOR ${ANAR_PARS_PARK_PRODUCT_VERSION_MINOR}
            VERSION_PATCH ${ANAR_PARS_PARK_PRODUCT_VERSION_PATCH}
            VERSION_REVISION ${ANAR_PARS_PARK_PRODUCT_VERSION_REVISION}
            COMPANY_NAME ${ANAR_PARS_PARK_PRODUCT_COMPANY_NAME}
            ICON ${ANAR_PARS_PARK_PRODUCT_ICON}
    )
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(DONT_SHOW_CONSOLE WIN32)
    endif ()
endif (WIN32)

configure_file("config.hpp.in" "config.hpp")

option(DEPLOYMENT "In development state show console for debug and see warnings and other console data" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(
        TS_FILES
        "locale/ParsPark_fa_IR.ts"
)

set(
        PARS_PARK_SOURCES

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
        service/model-binding/json/from-json-visitor.cpp
        service/model-binding/json/to-json-visitor.cpp

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

add_executable(
        ${PROJECT_NAME}
        ${DONT_SHOW_CONSOLE}
        ${PARS_PARK_SOURCES}
        ${ProductAnarParsParkVersionFiles}
        main.cpp
)
#    add_executable(
#            ${PROJECT_NAME}_Unit_Test
#            ${DONT_SHOW_CONSOLE}
#            ${PARS_PARK_SOURCES}
#            ${PARS_PARK_TEST_SOURCES}
#            ${ProductAnarParsParkVersionFiles}
#            test/main.cpp
#    )

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
        ${PARS_PARK_LIMEREPORT_LIB}
        ${PARS_PARK_NLOHMANN_JSON_LIB}
        ${PARS_PARK_ODB_LIB}
        ${PARS_PARK_ODB_MYSQL_LIB}
        ${PARS_PARK_OATPP_LIB}
        ${PARS_PARK_SERIAL_LIB}
        ${PARS_PARK_GOOGLE_LOG_LIB}
        ${PARS_PARK_GOOGLE_TEST_LIB}
        ${PARS_PARK_ANAR_COMMON_LIB}
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