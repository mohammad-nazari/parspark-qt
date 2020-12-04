cmake_minimum_required(VERSION 3.16)

project(ParsPark VERSION 1.0.0)

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

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("Generator: ${CMAKE_GENERATOR}")
message("C++ standard: ${CMAKE_CXX_STANDARD}")

#set(DCMAKE_SH "CMAKE_SH-NOTFOUND")

# For Poco
if (CMAKE_COMPILER_IS_MINGW)
    add_definitions(-DWC_NO_BEST_FIT_CHARS=0x400)   # Note - removed -DPOCO_WIN32_UTF8
    add_definitions(-D_WIN32 -DMINGW32 -DWINVER=0x500 -DODBCVER=0x0300 -DPOCO_THREAD_STACK_SIZE)
    add_compile_options(-Wa,-mbig-obj)   # Note: new - fixes "file too big"
endif ()

#option(ENABLE_DATA_MYSQL "Enable mysql option for find mysql package" ON)

set(ANAR_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(ANAR_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

set(ANAR_POCO_LIB poco)
set(ANAR_POCO_FOUNDATION_LIB Poco::Foundation)
set(ANAR_POCO_DATA_LIB Poco::Data)
#set(ANAR_POCO_DATA_MYSQL_LIB Poco::DataMySQL)
set(ANAR_LIMEREPORT_LIB limereport)
set(ANAR_PNG_LIB png)
set(ANAR_ZLIB_LIB zlib)
set(ANAR_ZINT_LIB zint)
set(ANAR_QZINT_LIB qzint)
set(ANAR_NLOHMANN_LIB nlohmann_json)
set(ANAR_OATPP_LIB oatpp)
set(ANAR_ODB_LIB odb)
set(ANAR_ODB_MYSQL_LIB odb-mysql)
set(ANAR_RS232_LIB rs232)
set(ANAR_MYSQL_LIB mysql)

set(ANAR_POCO_DIR "${ANAR_LIB_DIR}/${ANAR_POCO_LIB}")
set(ANAR_POCO_FOUNDATION_DIR "${ANAR_LIB_DIR}/${ANAR_POCO_LIB}/Foundation/include")
set(ANAR_POCO_DATA_DIR "${ANAR_LIB_DIR}/${ANAR_POCO_LIB}/Data/include")
#set(ANAR_POCO_DATA_MYSQL_DIR "${ANAR_LIB_DIR}/${ANAR_POCO_LIB}/Data/MySQL/include")
set(ANAR_LIMEREPORT_DIR "${ANAR_LIB_DIR}/${ANAR_LIMEREPORT_LIB}")
set(ANAR_PNG_DIR "${ANAR_LIB_DIR}/${ANAR_PNG_LIB}")
set(ANAR_ZLIB_DIR "${ANAR_LIB_DIR}/${ANAR_ZLIB_LIB}")
set(ANAR_ZINT_DIR "${ANAR_LIB_DIR}/${ANAR_ZINT_LIB}")
set(ANAR_QZINT_DIR "${ANAR_LIB_DIR}/${ANAR_QZINT_LIB}")
set(ANAR_NLOHMANN_DIR "${ANAR_LIB_DIR}/nlohmann/${ANAR_NLOHMANN_LIB}")
set(ANAR_OATPP_DIR "${ANAR_LIB_DIR}/${ANAR_OATPP_LIB}")
set(ANAR_ODB_DIR "${ANAR_LIB_DIR}/odb/${ANAR_ODB_LIB}")
set(ANAR_ODB_MYSQL_DIR "${ANAR_LIB_DIR}/odb/${ANAR_ODB_MYSQL_LIB}")
set(ANAR_RS232_DIR "${ANAR_LIB_DIR}/${ANAR_RS232_LIB}")
if (WIN32)
    set(ANAR_MYSQL_DIR "${ANAR_LIB_DIR}/${ANAR_MYSQL_LIB}/win/x64")
elseif (UNIX)
    set(ANAR_MYSQL_DIR "${ANAR_LIB_DIR}/${ANAR_MYSQL_LIB}/unix/x64")
endif ()

set(ANAR_LIB_BIN_DIR "${CMAKE_BINARY_DIR}/lib")
set(ANAR_POCO_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_POCO_LIB}")
#set(ANAR_LIMEREPORT_BIN_DIR "${ANAR_LIB_BIN_DIR}/nlohmann/${ANAR_LIMEREPORT_LIB}")
set(ANAR_PNG_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_PNG_LIB}")
set(ANAR_ZLIB_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_ZLIB_LIB}")
set(ANAR_ZINT_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_ZINT_LIB}")
set(ANAR_QZINT_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_QZINT_LIB}")
set(ANAR_NLOHMANN_BIN_DIR "${ANAR_LIB_BIN_DIR}/nlohmann/${ANAR_NLOHMANN_LIB}")
set(ANAR_OATPP_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_OATPP_LIB}")
set(ANAR_ODB_BIN_DIR "${ANAR_LIB_BIN_DIR}/odb/${ANAR_ODB_LIB}")
set(ANAR_ODB_MYSQL_BIN_DIR "${ANAR_LIB_BIN_DIR}/odb/${ANAR_ODB_MYSQL_LIB}")
set(ANAR_RS232_BIN_DIR "${ANAR_LIB_BIN_DIR}/${ANAR_RS232_LIB}")

#set(MYSQL_ROOT_DIR "${ANAR_MYSQL_DIR}") # POCO Set root installation path where to find include path and libraries of MySQL or MariaDB or
#set(MYSQL_ROOT_INCLUDE_DIRS "${ANAR_MYSQL_DIR}/include") # POCO Set include paths where to find MySQL or MariaDB headers
#set(MYSQL_ROOT_LIBRARY_DIRS "${ANAR_MYSQL_DIR}/lib") # POCO Set library paths where to find MySQL or MariaDB libraries

find_package(
        Qt5
        COMPONENTS
        Core
        LinguistTools
        Qml
        Quick
        REQUIRED
)

link_directories(
        "${ANAR_MYSQL_DIR}/lib"
)

include_directories(
        "${ANAR_LIB_DIR}"
        "${ANAR_MYSQL_DIR}/include"
        "${ANAR_NLOHMANN_DIR}/include"
        "${ANAR_POCO_FOUNDATION_DIR}"
        "${ANAR_POCO_DATA_DIR}"
        #        "${ANAR_POCO_DATA_MYSQL_DIR}"
        "${ANAR_ODB_DIR}"
        "${ANAR_ODB_MYSQL_DIR}"
        "${ANAR_SOURCE_DIR}"
)

add_subdirectory("${ANAR_POCO_DIR}")
add_subdirectory("${ANAR_LIMEREPORT_DIR}")
add_subdirectory("${ANAR_PNG_DIR}")
add_subdirectory("${ANAR_ZLIB_DIR}")
add_subdirectory("${ANAR_ZINT_DIR}")
add_subdirectory("${ANAR_QZINT_DIR}")
add_subdirectory("${ANAR_NLOHMANN_DIR}")
add_subdirectory("${ANAR_OATPP_DIR}")
add_subdirectory("${ANAR_ODB_DIR}")
add_subdirectory("${ANAR_ODB_MYSQL_DIR}")
add_subdirectory("${ANAR_RS232_DIR}")

set(
        TS_FILES
        "${CMAKE_SOURCE_DIR}/locale/ParsPark_fa_IR.ts"
)

set(
        PARSPARK_SOURCES

        resource/rc/icon.rc
        resource/qrc/qml.qrc

        src/common/string.cpp

        src/interface/i-fileable.cpp
        src/interface/i-stringable.cpp
        src/interface/i-a-jsonable.cpp

        src/model/settings/database.cpp
        src/model/settings/alpr.cpp
        src/model/settings/parking.cpp
        src/model/settings/comport.cpp
        src/model/settings/board.cpp
        src/model/settings/server.cpp
        src/model/settings/camera.cpp
        src/model/settings/gate.cpp
        src/model/settings/payment.cpp
        src/model/settings/software.cpp
        src/model/settings/card-reader.cpp
        src/model/settings/printer.cpp
        src/model/settings/settings.cpp
        src/model/user.cpp
        src/model/login.cpp
        src/model/base-model.cpp
        src/model/traffic.cpp
        src/model/database/person-odb.cxx

        src/database/i-database.cpp
        src/database/s-database.cpp
        src/database/mysql/mysql-database.cpp
        src/database/database-factory.cpp

        src/service/qt-std-converter.cpp
        src/service/base-service.cpp
        src/service/s-settings.cpp
        src/service/serial-port.cpp
        src/service/printer.cpp

        src/view/base-view.cpp
        src/view/common-view.cpp
        src/view/login/login-view.cpp
        src/view/settings/settings-view.cpp

        src/controller/base-controller.cpp
        src/controller/common-controller.cpp
        src/controller/login-controller.cpp
        src/controller/settings-controller.cpp

        src/main.cpp
        src/common/binary.cpp src/common/binary.hpp src/const/view-const.hpp)

add_executable(
        ${PROJECT_NAME}
        ${PARSPARK_SOURCES}
)

target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
        ${ANAR_ODB_LIB}
        ${ANAR_LIMEREPORT_LIB}
        ${ANAR_NLOHMANN_LIB}
        ${ANAR_MYSQL_LIB}
        ${ANAR_ODB_MYSQL_LIB}
        ${ANAR_POCO_FOUNDATION_LIB}
        ${ANAR_POCO_DATA_LIB}
        #        ${ANAR_POCO_DATA_MYSQL_LIB}
)

qt5_create_translation(
        QM_FILES
        ${TS_FILES}
)

if (WIN32)
    file(COPY "${ANAR_MYSQL_DIR}/lib/libmysql.dll"
            DESTINATION "${CMAKE_BINARY_DIR}/bin")
elseif (UNIX)
    file(COPY "${ANAR_MYSQL_DIR}/lib/libmysql.so"
            DESTINATION "${CMAKE_BINARY_DIR}/bin")
endif ()
add_executable( .clang-format)
add_executable(main src/main.cpp)