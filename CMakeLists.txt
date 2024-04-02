cmake_minimum_required(VERSION 3.5)

project(ParsPark LANGUAGES CXX)

set(PARS_PARK_MESSAGE "[[PARS_PARK]]")
function(ANAR_MESSAGE message)
    message("${PARS_PARK_MESSAGE} ${message}")
endfunction()

ANAR_MESSAGE("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

list(APPEND QT_COMPONENTS Core Gui Network PrintSupport Qml QmlModels QmlWorkerScript Quick QuickControls2 QuickTemplates2 Svg Widgets Xml UiTools LinguistTools Sql)
list(APPEND QT_PACKAGES)
foreach (QT_LIB ${QT_COMPONENTS})
    list(APPEND QT_PACKAGES Qt6::${QT_LIB})
endforeach ()

find_package(Qt6 COMPONENTS ${QT_COMPONENTS} REQUIRED)

if (WIN32)
    # Set minimum windows version to windows 7
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0601")
    #Or this adds a preprocessor definition to the project
    #    add_definitions(-D_WIN32_WINNT=0x0601)
endif ()

ANAR_MESSAGE("Generator: ${CMAKE_GENERATOR}")
ANAR_MESSAGE("C++ standard: ${CMAKE_CXX_STANDARD}")

set(PARS_PARK_LIB_DIR "${CMAKE_SOURCE_DIR}/libs")
set(PARS_PARK_LIB_BIN_DIR "${CMAKE_BINARY_DIR}/libs")
set(PARS_PARK_ANAR_LIB_DIR "${PARS_PARK_LIB_DIR}/anar")
set(PARS_PARK_APP_DIR "${CMAKE_SOURCE_DIR}/src")
set(PARS_PARK_UNIT_TEST_DIR "${CMAKE_SOURCE_DIR}/test")

#region QT
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")
#endregion

#region MYSQL
add_definitions(-DDATABASE_MYSQL)
set(PARS_PARK_MYSQL_FOLDER mysql)
if (WIN32)
    set(PARS_PARK_MYSQL_LIB mysql)
    set(PARS_PARK_MYSQL_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_MYSQL_FOLDER}/mysql-connector-c/win/x64")
    file(
            COPY "${PARS_PARK_MYSQL_DIR}/libs/libmysql.dll"
            DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
else ()
    set(PARS_PARK_MYSQL_LIB mysqlclient)
endif ()
set(MYSQL_ROOT_DIR "${PARS_PARK_MYSQL_DIR}")
#endregion

#region ZLIB
set(PARS_PARK_ZLIB_LIB zlib)
set(PARS_PARK_ZLIB_FOLDER zlib)
set(PARS_PARK_ZLIB_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ZLIB_FOLDER}")
set(PARS_PARK_ZLIB_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_ZLIB_FOLDER}")
set(ZLIB_INCLUDE_DIR "${PARS_PARK_ZLIB_DIR}")
#endregion

#region PNG
set(PARS_PARK_PNG_LIB png)
set(PARS_PARK_PNG_FOLDER png)
set(PARS_PARK_PNG_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_PNG_FOLDER}")
set(PARS_PARK_PNG_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_PNG_FOLDER}")
#endregion

#region ZINT
set(ZINT_UNINSTALL OFF)
set(PARS_PARK_ZINT_LIB zint)
set(PARS_PARK_ZINT_FOLDER zint)
set(PARS_PARK_ZINT_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ZINT_FOLDER}")
set(PARS_PARK_ZINT_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_ZINT_LIB}")
#endregion

#region QZINT
set(PARS_PARK_QZINT_LIB qzint)
set(PARS_PARK_QZINT_FOLDER qzint)
set(PARS_PARK_QZINT_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_QZINT_FOLDER}")
set(PARS_PARK_QZINT_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_QZINT_FOLDER}")
#endregion

#region Poco
if (CMAKE_COMPILER_IS_MINGW)
    add_definitions(-DWC_NO_BEST_FIT_CHARS=0x400)   # Note - removed -DPOCO_WIN32_UTF8
    add_definitions(-D_WIN32 -DMINGW32 -DWINVER=0x500 -DODBCVER=0x0300 -DPOCO_THREAD_STACK_SIZE)
    add_compile_options(-Wa,-mbig-obj)   # Note: new - fixes "file too big"
endif ()
set(PARS_PARK_POCO_LIB Poco)
set(PARS_PARK_POCO_FOUNDATION_LIB "${PARS_PARK_POCO_LIB}::Foundation")
set(PARS_PARK_POCO_FOLDER poco)
set(PARS_PARK_POCO_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_POCO_FOLDER}")
set(PARS_PARK_POCO_FOUNDATION_DIR "${PARS_PARK_POCO_DIR}/Foundation/include")
#endregion

#region Lime Report
set(PARS_PARK_LIMEREPORT_LIB limereport-qt6)
set(ENABLE_ZINT ON)
set(LIMEREPORT_DEMO ON)
set(USE_QT6 ON)
set(PARS_PARK_LIMEREPORT_FOLDER lime-report)
set(PARS_PARK_LIMEREPORT_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_LIMEREPORT_FOLDER}")
#endregion

#region nlohmann
set(PARS_PARK_NLOHMANN_JSON_LIB nlohmann_json::nlohmann_json)
set(PARS_PARK_NLOHMANN_FOLDER nlohmann)
set(PARS_PARK_NLOHMANN_JSON_FOLDER nlohmann-json)
set(PARS_PARK_NLOHMANN_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_NLOHMANN_FOLDER}")
set(PARS_PARK_NLOHMANN_JSON_DIR "${PARS_PARK_NLOHMANN_DIR}/${PARS_PARK_NLOHMANN_JSON_FOLDER}")
#endregion

#region OATPP
set(PARS_PARK_OATPP_LIB oatpp)
set(PARS_PARK_OATPP_FOLDER oatpp)
set(PARS_PARK_OATPP_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_OATPP_FOLDER}")
#endregion

#region ODB
set(PARS_PARK_ODB_LIB libodb)
set(PARS_PARK_ODB_MYSQL_LIB ODB::MySQL)
set(PARS_PARK_ODB_ALL_FOLDER odb)
set(PARS_PARK_ODB_FOLDER libodb)
set(PARS_PARK_ODB_MYSQL_FOLDER libodb-mysql)
set(PARS_PARK_ODB_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ODB_ALL_FOLDER}/${PARS_PARK_ODB_FOLDER}")
set(PARS_PARK_ODB_MYSQL_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ODB_ALL_FOLDER}/${PARS_PARK_ODB_MYSQL_FOLDER}")
#endregion

#region Serial
set(PARS_PARK_SERIAL_LIB serial)
set(PARS_PARK_SERIAL_FOLDER serial)
set(PARS_PARK_SERIAL_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_SERIAL_FOLDER}")
#endregion

#region GLog
set(PARS_PARK_GOOGLE_LOG_LIB glog)
set(PARS_PARK_GOOGLE_LOG_FOLDER googlelog)
set(PARS_PARK_GOOGLE_LOG_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_GOOGLE_LOG_FOLDER}")
#endregion

#region GTest
set(PARS_PARK_GOOGLE_TEST_LIB gtest)
set(PARS_PARK_GOOGLE_TEST_FOLDER googletest)
set(PARS_PARK_GOOGLE_TEST_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_GOOGLE_TEST_FOLDER}")
#endregion

#region ANAR lib
set(PARS_PARK_ANAR_LIB Anar)

#region ANAR Const lib
set(PARS_PARK_ANAR_COMMON_LIB "${PARS_PARK_ANAR_LIB}::Common")
set(PARS_PARK_ANAR_COMMON_LIB_FOLDER "common")
set(PARS_PARK_ANAR_COMMON_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_COMMON_LIB_FOLDER}")
#endregion ANAR Const lib
#endregion Anar Lib

#region Anar Pars Park App
set(PARS_PARK_PARS_PARK_APP "${PARS_PARK_ANAR_LIB}::ParsPark")
#endregion Anar Pars Park App

if (WIN32)
    link_directories(
            "${PARS_PARK_MYSQL_DIR}/lib"
    )
endif (WIN32)

include_directories(
        "${PARS_PARK_ODB_DIR}"
        "${PARS_PARK_ODB_MYSQL_DIR}"
        "${PARS_PARK_SERIAL_DIR}/include"
)

#add_subdirectory("${PARS_PARK_ZLIB_DIR}")
#add_subdirectory("${PARS_PARK_PNG_DIR}")
#add_subdirectory("${PARS_PARK_ZINT_DIR}")
#add_subdirectory("${PARS_PARK_QZINT_DIR}")
#add_subdirectory("${PARS_PARK_LIMEREPORT_DIR}")
add_subdirectory("${PARS_PARK_POCO_DIR}")
add_subdirectory("${PARS_PARK_NLOHMANN_JSON_DIR}")
add_subdirectory("${PARS_PARK_OATPP_DIR}")
add_subdirectory("${PARS_PARK_ODB_DIR}")
add_subdirectory("${PARS_PARK_ODB_MYSQL_DIR}")
add_subdirectory("${PARS_PARK_SERIAL_DIR}")
add_subdirectory("${PARS_PARK_GOOGLE_LOG_DIR}")
add_subdirectory("${PARS_PARK_ANAR_LIB_DIR}")
add_subdirectory("${PARS_PARK_GOOGLE_TEST_DIR}")
add_subdirectory("${PARS_PARK_UNIT_TEST_DIR}")

file(
        MAKE_DIRECTORY
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/logs"
)

if (WIN32)
    set(DEBUG_SUFFIX)
    if ((CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") AND (CMAKE_BUILD_TYPE MATCHES "Debug"))
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${QTDIR5}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        file(
                COPY "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/plugins/platforms/"
        )
    endif ()
    foreach (QT_LIB ${QT_COMPONENTS})
        if (EXISTS "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll")
            file(
                    COPY "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
            )
        endif ()
    endforeach ()
    file(
            COPY "${QT_INSTALL_PATH}/qml"
            DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
endif ()

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

qt_standard_project_setup(REQUIRES 6.5)

set(
        TS_FILES
        "locale/ParsPark_fa_IR.ts"
)

set(
        PARS_PARK_SOURCES

        #        ${CMAKE_SOURCE_DIR}/resource/qrc/qml.qrc

        ${CMAKE_SOURCE_DIR}/src/service/qt-std-converter.cpp
        ${CMAKE_SOURCE_DIR}/src/service/s-settings.cpp
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/person-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/user-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/create-modify-delete-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/card-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/car-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/black-list-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/driver-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/lost-card-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/organization-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/parking-log-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/database/mysql/subscription-model-odb.cxx
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/json/from-json-visitor.cpp
        ${CMAKE_SOURCE_DIR}/src/service/model-binding/json/to-json-visitor.cpp

        #        ${CMAKE_SOURCE_DIR}/src/view/View.cpp
        #        ${CMAKE_SOURCE_DIR}/src/view/View.hpp
        #        ${CMAKE_SOURCE_DIR}/src/view/CommonView.cpp
        #        ${CMAKE_SOURCE_DIR}/src/view/CommonView.hpp
        #        ${CMAKE_SOURCE_DIR}/src/view/login/LoginView.cpp
        #        ${CMAKE_SOURCE_DIR}/src/view/login/LoginView.hpp
        #        ${CMAKE_SOURCE_DIR}/src/view/settings/SettingsView.cpp
        #        ${CMAKE_SOURCE_DIR}/src/view/settings/SettingsView.hpp
        #        ${CMAKE_SOURCE_DIR}/src/view/SView.cpp
        #        ${CMAKE_SOURCE_DIR}/src/view/SView.hpp

        ${CMAKE_SOURCE_DIR}/src/controller/login-controller.cpp
        ${CMAKE_SOURCE_DIR}/src/controller/settings-controller.cpp

        ${CMAKE_SOURCE_DIR}/src/nazari-test.cpp

        ${CMAKE_SOURCE_DIR}/src/main.cpp
)

set(
        PARS_PARK_TEST_SOURCES
)

qt_add_executable(
        ${PROJECT_NAME}
        ${DONT_SHOW_CONSOLE}
        ${PARS_PARK_SOURCES}
        ${ProductAnarParsParkVersionFiles}
)

qt_add_qml_module(
        ${PROJECT_NAME}

        URI "ANAR.ParsPark.View"

        QML_FILES
        src/view/common/CommonButton.qml
        src/view/common/CommonComboBox.qml
        src/view/common/CommonCOMPort.qml
        src/view/common/CommonDateAndTime.qml
        src/view/common/CommonDetailsTable.qml
        src/view/common/CommonDigitalClock.qml
        src/view/common/CommonNumericComboBox.qml
        src/view/common/CommonParkingCapacity.qml
        src/view/common/CommonPicture.qml
        src/view/common/CommonPlate.qml
        src/view/common/CommonServer.qml
        src/view/common/CommonSpinBox.qml
        src/view/common/CommonStatus.qml
        src/view/common/CommonTextField.qml
        src/view/login/Login.qml
        src/view/main/Main.qml
        src/view/main/MainColumnLayout.qml
        src/view/main/MainEnterSection.qml
        src/view/main/MainExitSection.qml
        src/view/main/MainMiddleSection.qml
        src/view/settings/ALPRTab.qml
        src/view/settings/BoardTab.qml
        src/view/settings/CameraTab.qml
        src/view/settings/CardReaderTab.qml
        src/view/settings/DataBaseTab.qml
        src/view/settings/GateTab.qml
        src/view/settings/ParkingInfoTab.qml
        src/view/settings/PaymentTab.qml
        src/view/settings/PrinterTab.qml
        src/view/settings/SoftwareTab.qml
        src/view/settings/Settings.qml

        SOURCES
        src/view/View.cpp
        src/view/View.hpp
        src/view/CommonView.cpp
        src/view/CommonView.hpp
        src/view/login/LoginView.cpp
        src/view/login/LoginView.hpp
        src/view/settings/SettingsView.cpp
        src/view/settings/SettingsView.hpp
        src/view/SView.cpp
        src/view/SView.hpp

        RESOURCES
        resource/rc/icon.rc
        image/icon/About.ico
        image/png/About128.png
        image/png/About48.png
        image/png/About64.png
        image/icon/Aha-Soft-Large-Seo-SEO.ico
        image/png/ArrowsEn.png
        image/png/ArrowsEx.png
        image/png/ArrowsSync.png
        image/icon/barrier128.ico
        image/png/barrier128.png
        image/png/barrier64.png
        image/png/barrier_closed.png
        image/icon/blacklist128.ico
        image/png/blacklist128.png
        image/png/blacklist64.png
        image/png/BlueCar128.png
        image/png/BlueCar64.png
        image/icon/board.ico
        image/png/board.png
        image/png/Camera.png
        image/icon/camera128.ico
        image/png/camera128.png
        image/icon/camera2.ico
        image/png/camera64.png
        image/icon/Car.ico
        image/jpeg/car.jpg
        image/png/car.png
        image/png/car1.png
        image/png/car2.png
        image/icon/Card-Reader128.ico
        image/png/Card-Reader128.png
        image/png/Card-Reader48.png
        image/png/Card-Reader64.png
        image/png/carusers128.png
        image/png/carusers48.png
        image/icon/carusers64.ico
        image/png/carusers64.png
        image/png/check.png
        image/png/cost.png
        image/png/credit_card-512.png
        image/png/database128.png
        image/png/database64.png
        image/png/details.png
        image/png/down.png
        image/jpeg/download.jpg
        image/png/duration.png
        image/png/edit.png
        image/png/exit128.png
        image/png/exit48.png
        image/icon/exit64.ico
        image/png/exit64.png
        image/png/hotovo.png
        image/icon/Icon1.ico
        image/png/Icon1.png
        image/icon/Icon2.ico
        image/png/Icon2.png
        image/icon/Icon3.ico
        image/png/Icon3.png
        image/icon/Icons-Land-Vista-People-Person-Male-Light.ico
        image/icon/image.ico
        image/png/left.png
        image/png/license128.png
        image/png/license64.png
        image/icon/Login128.ico
        image/png/Login128.png
        image/png/Login64.png
        image/png/parking.png
        image/jpeg/Payment.jpg
        image/png/Payment128.png
        image/png/Payment64.png
        image/png/person.png
        image/png/plate.png
        image/png/printer-icon.png
        image/png/Printer128.png
        image/png/Printer64.png
        image/icon/register.ico
        image/png/register.png
        image/png/right.png
        image/png/row.png
        image/png/search32.png
        image/png/search64.png
        image/png/Settings128.png
        image/png/Settings32.png
        image/png/Settings48.png
        image/icon/Settings64.ico
        image/png/software128.png
        image/png/software64.png
        image/png/software_dev128.png
        image/png/software_dev64.png
        image/png/statistica128.png
        image/png/statistica48.png
        image/png/statistica64.png
        image/icon/Stop128.ico
        image/png/Stop128.png
        image/png/Stop48.png
        image/png/Stop64.png
        image/png/type.png
        image/png/users128.png
        image/png/users48.png
        image/icon/users64.ico
        image/png/users64.png
)

target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>:QT_QML_DEBUG>
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        Qt6::Core
        Qt6::Qml
        Qt6::Quick
        ${PARS_PARK_MYSQL_LIB}
        ${PARS_PARK_POCO_FOUNDATION_LIB}
        #        ${PARS_PARK_LIMEREPORT_LIB}
        ${PARS_PARK_NLOHMANN_JSON_LIB}
        ${PARS_PARK_ODB_LIB}
        ${PARS_PARK_ODB_MYSQL_LIB}
        ${PARS_PARK_OATPP_LIB}
        ${PARS_PARK_SERIAL_LIB}
        ${PARS_PARK_GOOGLE_LOG_LIB}
        ${PARS_PARK_GOOGLE_TEST_LIB}
        ${PARS_PARK_ANAR_COMMON_LIB}
)

qt6_create_translation(
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

#  cd D:\Projects\Desktop\ParsPark\QT\ParsPark\src\service\model-binding\database\mysql
# odb.exe --std c++11 --hxx-prologue '#include \"service/model-binding/database/traits/traits.hxx\"' --database mysql -ID:\Projects\Desktop\ParsPark\QT\ParsPark\src -ID:\Projects\Desktop\ParsPark\QT\ParsPark\src\anar\common\include -ID:\Projects\Desktop\ParsPark\QT\ParsPark\lib\poco\Foundation\include -ID:\Projects\Desktop\ParsPark\QT\ParsPark\lib\nlohmann\nlohmann-json\include --generate-schema --generate-query D:\Projects\Desktop\ParsPark\QT\ParsPark\src\model\database\*-model.hppxx

#  cd D:\Projects\Desktop\ParsPark\QT\ParsPark\src\service\model-binding\database\mysql
# odb.exe --std c++11 --hxx-prologue '#include \"service/model-binding/database/traits/traits.hxx\"' --database mysql -ID:\Projects\Desktop\ParsPark\QT\ParsPark\src -ID:\Projects\Desktop\ParsPark\QT\ParsPark\src\anar\common\include -ID:\Projects\Desktop\ParsPark\QT\ParsPark\libs\poco\Foundation\include -ID:\Projects\Desktop\ParsPark\QT\ParsPark\libs\nlohmann\nlohmann-json\include --generate-schema --generate-query D:\Projects\Desktop\ParsPark\QT\ParsPark\src\model\database\*-model.hpp
