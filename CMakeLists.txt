cmake_minimum_required(VERSION 3.5)

project(ParsParkProject)

set(PARS_PARK_MESSAGE "[[PARS_PARK]]")
function(ANAR_MESSAGE message)
    message("${PARS_PARK_MESSAGE} ${message}")
endfunction()

ANAR_MESSAGE("QT5 dir: ${QTDIR5}")

ANAR_MESSAGE("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

list(APPEND QT_COMPONENTS Core Gui Network PrintSupport Qml QmlModels QmlWorkerScript Quick QuickControls2 QuickTemplates2 Script ScriptTools Svg Widgets Xml XmlPatterns UiTools LinguistTools Sql)
list(APPEND QT_PACKAGES)
foreach (QT_LIB ${QT_COMPONENTS})
    list(APPEND QT_PACKAGES Qt5::${QT_LIB})
endforeach ()

find_package(Qt5 COMPONENTS ${QT_COMPONENTS} REQUIRED)

if (WIN32)
    # Set minimum windows version to windows 7
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0601")
    #Or this adds a preprocessor definition to the project
    #    add_definitions(-D_WIN32_WINNT=0x0601)
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ANAR_MESSAGE("Generator: ${CMAKE_GENERATOR}")
ANAR_MESSAGE("C++ standard: ${CMAKE_CXX_STANDARD}")

set(PARS_PARK_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(PARS_PARK_LIB_BIN_DIR "${CMAKE_BINARY_DIR}/lib")
set(PARS_PARK_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(PARS_PARK_ANAR_LIB_DIR "${PARS_PARK_SOURCE_DIR}/anar")
set(PARS_PARK_APP_DIR "${PARS_PARK_SOURCE_DIR}/app")
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
            COPY "${PARS_PARK_MYSQL_DIR}/lib/libmysql.dll"
            DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
else()
    set(PARS_PARK_MYSQL_LIB mysqlclient)
endif ()
set(MYSQL_ROOT_DIR "${PARS_PARK_MYSQL_DIR}")
#endregion

#region ZLIB
set(PARS_PARK_ZLIB_LIB zlib)
set(ZLIB_LIBRARY ${PARS_PARK_ZLIB_LIB})
set(PARS_PARK_ZLIB_FOLDER zlib)
set(PARS_PARK_ZLIB_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ZLIB_FOLDER}")
set(PARS_PARK_ZLIB_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_ZLIB_FOLDER}")
set(ZLIB_INCLUDE_DIR ${PARS_PARK_ZLIB_DIR})
#endregion

#region PNG
set(PARS_PARK_PNG_LIB png)
set(PARS_PARK_PNG_FOLDER png)
set(PARS_PARK_PNG_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_PNG_FOLDER}")
set(PARS_PARK_PNG_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_PNG_FOLDER}")
#endregion

#region ZINT
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
set(PARS_PARK_POCO_FOUNDATION_LIB ${PARS_PARK_POCO_LIB}::Foundation)
set(PARS_PARK_POCO_FOLDER poco)
set(PARS_PARK_POCO_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_POCO_FOLDER}")
set(PARS_PARK_POCO_FOUNDATION_DIR "${PARS_PARK_POCO_DIR}/Foundation/include")
#endregion

#region Lime Report
set(PARS_PARK_LIMEREPORT_LIB limereport)
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
set(PARS_PARK_ODB_LIB odb)
set(PARS_PARK_ODB_MYSQL_LIB ODB::MySQL)
set(PARS_PARK_ODB_ALL_FOLDER odb)
set(PARS_PARK_ODB_FOLDER odb)
set(PARS_PARK_ODB_MYSQL_FOLDER odb-mysql)
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
set(PARS_PARK_ANAR_COMMON_LIB ${PARS_PARK_ANAR_LIB}::Common)
set(PARS_PARK_ANAR_COMMON_LIB_FOLDER "common")
set(PARS_PARK_ANAR_COMMON_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_COMMON_LIB_FOLDER}")
#endregion ANAR Const lib
#endregion Anar Lib

#region Anar Pars Park App
set(PARS_PARK_PARS_PARK_APP ${PARS_PARK_ANAR_LIB}::ParsPark)
set(PARS_PARK_PARS_PARK_APP_FOLDER "pars-park-app")
set(PARS_PARK_PARS_PARK_APP_DIR "${PARS_PARK_APP_DIR}/${PARS_PARK_PARS_PARK_APP_FOLDER}")
#endregion Anar Pars Park App

link_directories(
        "${QTDIR5}/lib"
        "${PARS_PARK_MYSQL_DIR}/lib"
)

include_directories(
        "${QTDIR5}/include"
        "${PARS_PARK_PNG_BIN_DIR}"
        "${PARS_PARK_PNG_DIR}"
        "${PARS_PARK_ZLIB_BIN_DIR}"
        "${PARS_PARK_ZLIB_DIR}"
        "${PARS_PARK_ZINT_BIN_DIR}"
        "${PARS_PARK_ZINT_DIR}"
        "${PARS_PARK_QZINT_BIN_DIR}"
        "${PARS_PARK_QZINT_DIR}"
        "${PARS_PARK_LIB_DIR}"
        "${PARS_PARK_MYSQL_DIR}/include"
        "${PARS_PARK_POCO_FOUNDATION_DIR}"
        "${PARS_PARK_NLOHMANN_JSON_DIR}/include"
        "${PARS_PARK_OATPP_DIR}"
        "${PARS_PARK_ODB_DIR}"
        "${PARS_PARK_ODB_MYSQL_DIR}"
        "${PARS_PARK_SERIAL_DIR}/include"
        "${PARS_PARK_GOOGLE_LOG_DIR}/src"
        "${PARS_PARK_GOOGLE_TEST_DIR}/${PARS_PARK_GOOGLE_TEST_FOLDER}/include"
        "${PARS_PARK_ANAR_COMMON_LIB_DIR}/include"
        "${PARS_PARK_PARS_PARK_APP_DIR}"
)

add_subdirectory("${PARS_PARK_ZLIB_DIR}")
add_subdirectory("${PARS_PARK_PNG_DIR}")
add_subdirectory("${PARS_PARK_ZINT_DIR}")
add_subdirectory("${PARS_PARK_QZINT_DIR}")
add_subdirectory("${PARS_PARK_LIMEREPORT_DIR}")
add_subdirectory("${PARS_PARK_POCO_DIR}")
add_subdirectory("${PARS_PARK_NLOHMANN_JSON_DIR}")
add_subdirectory("${PARS_PARK_OATPP_DIR}")
add_subdirectory("${PARS_PARK_ODB_DIR}")
add_subdirectory("${PARS_PARK_ODB_MYSQL_DIR}")
add_subdirectory("${PARS_PARK_SERIAL_DIR}")
add_subdirectory("${PARS_PARK_GOOGLE_LOG_DIR}")
add_subdirectory("${PARS_PARK_ANAR_LIB_DIR}")
add_subdirectory("${PARS_PARK_PARS_PARK_APP_DIR}")
add_subdirectory("${PARS_PARK_GOOGLE_TEST_DIR}")
add_subdirectory("${PARS_PARK_UNIT_TEST_DIR}")

file(
        MAKE_DIRECTORY
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/logs
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
        if (EXISTS "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll")
            file(
                    COPY "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
            )
        endif ()
    endforeach ()
    file(
            COPY "${QT_INSTALL_PATH}/qml"
            DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
endif ()
#d:\Tools\ODB\odb-compiler\bin\odb.exe -d mysql --generate-query --generate-schema --std c++11 person.hxx
#d:\Tools\ODB\odb-compiler\bin\odb.exe --std c++11 --database mysql --generate-schema --generate-query --hxx-prologue "#include \"traits.hxx\""  --table-prefix mapping_ person.hxx