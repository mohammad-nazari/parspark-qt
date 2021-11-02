cmake_minimum_required(VERSION 3.5)

project(ParsParkProject)

set(PARS_PARK_MESSAGE "[[PARS_PARK]]")
message("${PARS_PARK_MESSAGE} QT dir: ${QTDIR}")

if (WIN32)
    # Set minimum windows version to windows 7
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0601")
    #Or this adds a preprocessor definition to the project
    #    add_definitions(-D_WIN32_WINNT=0x0601)
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("${PARS_PARK_MESSAGE} Generator: ${CMAKE_GENERATOR}")
message("${PARS_PARK_MESSAGE} C++ standard: ${CMAKE_CXX_STANDARD}")

set(PARS_PARK_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(PARS_PARK_LIB_BIN_DIR "${CMAKE_BINARY_DIR}/lib")
set(PARS_PARK_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(PARS_PARK_ANAR_LIB_DIR "${PARS_PARK_SOURCE_DIR}/anar")
set(PARS_PARK_APP_DIR "${PARS_PARK_SOURCE_DIR}/app")

#region QT
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")
#endregion

#region MYSQL
add_definitions(-DDATABASE_MYSQL)
#set(ENABLE_DATA_MYSQL true)
#set(MYSQL_FOUND true)
set(PARS_PARK_MYSQL_LIB mysql)
set(PARS_PARK_MYSQL_FOLDER mysql)
if (WIN32)
    set(PARS_PARK_MYSQL_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_MYSQL_FOLDER}/mysql-connector-c/win/x64")
elseif (UNIX)
    set(PARS_PARK_MYSQL_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_MYSQL_FOLDER}/mysql-connector-c/unix/x64")
endif ()
set(MYSQL_ROOT_DIR "${PARS_PARK_MYSQL_DIR}")
#set(PC_MYSQL_DIR "${PARS_PARK_MYSQL_DIR}")
#set(MYSQL_ROOT_INCLUDE_DIRS "${PARS_PARK_MYSQL_DIR}/include")
#set(PC_MYSQL_INCLUDE_DIRS "${PARS_PARK_MYSQL_DIR}/include")
#set(MYSQL_ROOT_LIBRARY_DIRS "${PARS_PARK_MYSQL_DIR}/lib")
#set(PC_MYSQL_LIBRARY_DIRS "${PARS_PARK_MYSQL_DIR}/lib")
if (WIN32)
    file(COPY "${PARS_PARK_MYSQL_DIR}/lib/libmysql.dll"
            DESTINATION "${CMAKE_BINARY_DIR}/bin")
elseif (UNIX)
    file(COPY "${PARS_PARK_MYSQL_DIR}/lib/libmysql.so"
            DESTINATION "${CMAKE_BINARY_DIR}/bin")
endif ()
#endregion

#region PNG
set(PARS_PARK_PNG_LIB png)
set(PARS_PARK_PNG_FOLDER png)
set(PARS_PARK_PNG_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_PNG_FOLDER}")
set(PARS_PARK_PNG_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_PNG_FOLDER}")
#endregion

#region ZLIB
set(PARS_PARK_ZLIB_LIB zlib)
set(PARS_PARK_ZLIB_FOLDER zlib)
set(PARS_PARK_ZLIB_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ZLIB_FOLDER}")
set(PARS_PARK_ZLIB_BIN_DIR "${PARS_PARK_LIB_BIN_DIR}/${PARS_PARK_ZLIB_FOLDER}")
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
#set(PARS_PARK_POCO_DATA_LIB ${PARS_PARK_POCO_LIB}::Data)
#set(PARS_PARK_POCO_DATA_MYSQL_LIB ${PARS_PARK_POCO_LIB}::DataMySQL)
#set(PARS_PARK_POCO_DATA_SQLITE_LIB ${PARS_PARK_POCO_LIB}::DataSQLite)
set(PARS_PARK_POCO_FOLDER poco)
set(PARS_PARK_POCO_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_POCO_FOLDER}")
set(PARS_PARK_POCO_FOUNDATION_DIR "${PARS_PARK_POCO_DIR}/Foundation/include")
#set(PARS_PARK_POCO_DATA_DIR "${PARS_PARK_POCO_DIR}/Data/include")
#set(PARS_PARK_POCO_DATA_MYSQL_DIR "${PARS_PARK_POCO_DIR}/Data/MySQL/include")
#set(PARS_PARK_POCO_DATA_SQLITE_DIR "${PARS_PARK_POCO_DIR}/Data/SQLite/include")
#endregion

#region Lime Report
set(PARS_PARK_LIMEREPORT_LIB limereport)
set(PARS_PARK_LIMEREPORT_FOLDER lime-report)
set(PARS_PARK_LIMEREPORT_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_LIMEREPORT_FOLDER}")
#endregion

#region nlohmann
set(PARS_PARK_NLOHMANN_JSON_LIB nlohman::json)
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
set(PARS_PARK_ODB_FOLDER odb)
set(PARS_PARK_ODB_MYSQL_FOLDER odb-mysql)
set(PARS_PARK_ODB_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ODB_FOLDER}/${PARS_PARK_ODB_FOLDER}")
set(PARS_PARK_ODB_MYSQL_DIR "${PARS_PARK_LIB_DIR}/${PARS_PARK_ODB_FOLDER}/${PARS_PARK_ODB_MYSQL_FOLDER}")
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
set(PARS_PARK_ANAR_CONST_LIB ${PARS_PARK_ANAR_LIB}::Const)
set(PARS_PARK_ANAR_CONST_LIB_FOLDER "const")
set(PARS_PARK_ANAR_CONST_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_CONST_LIB_FOLDER}")
#endregion ANAR Const lib

#region ANAR Controller lib
set(PARS_PARK_ANAR_CONTROLLER_LIB ${PARS_PARK_ANAR_LIB}::Controller)
set(PARS_PARK_ANAR_CONTROLLER_LIB_FOLDER "controller")
set(PARS_PARK_ANAR_CONTROLLER_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_CONTROLLER_LIB_FOLDER}")
#endregion ANAR Controller lib

#region ANAR Database lib
set(PARS_PARK_ANAR_DATABASE_LIB ${PARS_PARK_ANAR_LIB}::Database)
set(PARS_PARK_ANAR_DATABASE_LIB_FOLDER "database")
set(PARS_PARK_ANAR_DATABASE_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_DATABASE_LIB_FOLDER}")
#endregion ANAR Database lib

#region ANAR Exception lib
set(PARS_PARK_ANAR_EXCEPTION_LIB ${PARS_PARK_ANAR_LIB}::Exception)
set(PARS_PARK_ANAR_EXCEPTION_LIB_FOLDER "exception")
set(PARS_PARK_ANAR_EXCEPTION_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_EXCEPTION_LIB_FOLDER}")
#endregion ANAR Exception lib

#region ANAR Interface lib
set(PARS_PARK_ANAR_INTERFACE_LIB ${PARS_PARK_ANAR_LIB}::Interface)
set(PARS_PARK_ANAR_INTERFACE_LIB_FOLDER "interface")
set(PARS_PARK_ANAR_INTERFACE_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_INTERFACE_LIB_FOLDER}")
#endregion ANAR Interface lib

#region ANAR Log lib
set(PARS_PARK_ANAR_LOG_LIB ${PARS_PARK_ANAR_LIB}::Log)
set(PARS_PARK_ANAR_LOG_LIB_FOLDER "log")
set(PARS_PARK_ANAR_LOG_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_LOG_LIB_FOLDER}")
#endregion ANAR Log lib

#region ANAR Model lib
set(PARS_PARK_ANAR_MODEL_LIB ${PARS_PARK_ANAR_LIB}::Model)
set(PARS_PARK_ANAR_MODEL_LIB_FOLDER "model")
set(PARS_PARK_ANAR_MODEL_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_MODEL_LIB_FOLDER}")
#endregion ANAR Model lib

#region Anar Service Lib
set(PARS_PARK_ANAR_SERVICE_LIB ${PARS_PARK_ANAR_LIB}::Service)
set(PARS_PARK_ANAR_SERVICE_LIB_FOLDER "service")
set(PARS_PARK_ANAR_SERVICE_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_SERVICE_LIB}")
#endregion Anar Service Lib

#region ANAR Task lib
set(PARS_PARK_ANAR_TASK_LIB ${PARS_PARK_ANAR_LIB}::Task)
set(PARS_PARK_ANAR_TASK_LIB_FOLDER "task")
set(PARS_PARK_ANAR_TASK_LIB_DIR "${PARS_PARK_ANAR_LIB_DIR}/${PARS_PARK_ANAR_TASK_LIB_FOLDER}")
#endregion ANAR Task lib
#endregion Anar Lib

#region Anar Pars Park App
set(PARS_PARK_PARS_PARK_APP ${PARS_PARK_ANAR_LIB}::ParsPark)
set(PARS_PARK_PARS_PARK_APP_FOLDER "pars-park-app")
set(PARS_PARK_PARS_PARK_APP_DIR "${PARS_PARK_APP_DIR}/${PARS_PARK_PARS_PARK_APP_FOLDER}")
#endregion Anar Pars Park App

link_directories(
        "${PARS_PARK_MYSQL_DIR}/lib"
)

include_directories(
        "${PARS_PARK_PNG_BIN_DIR}"
        "${PARS_PARK_PNG_DIR}"
        "${PARS_PARK_ZLIB_BIN_DIR}"
        "${PARS_PARK_ZLIB_DIR}"
        "${PARS_PARK_QZINT_BIN_DIR}"
        "${PARS_PARK_QZINT_DIR}"
        "${PARS_PARK_ZINT_BIN_DIR}"
        "${PARS_PARK_ZINT_DIR}"
        "${PARS_PARK_LIB_DIR}"
        "${PARS_PARK_MYSQL_DIR}/include"
        "${PARS_PARK_NLOHMANN_JSON_DIR}/include"
        "${PARS_PARK_POCO_FOUNDATION_DIR}"
#        "${PARS_PARK_POCO_DATA_DIR}"
#        "${PARS_PARK_POCO_DATA_MYSQL_DIR}"
#        "${PARS_PARK_POCO_DATA_SQLITE_DIR}"
        "${PARS_PARK_ODB_DIR}"
        "${PARS_PARK_ODB_MYSQL_DIR}"
        "${PARS_PARK_SERIAL_DIR}/include"
        "${PARS_PARK_GOOGLE_LOG_DIR}/src"
        "${PARS_PARK_GOOGLE_TEST_DIR}/${PARS_PARK_GOOGLE_TEST_DIR}/include"
        "${PARS_PARK_SOURCE_DIR}"
        "${PARS_PARK_PARS_PARK_APP_DIR}"
)

add_subdirectory("${PARS_PARK_PNG_DIR}")
add_subdirectory("${PARS_PARK_ZLIB_DIR}")
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
add_subdirectory("${PARS_PARK_GOOGLE_TEST_DIR}")
add_subdirectory("${PARS_PARK_ANAR_LIB_DIR}")
add_subdirectory("${PARS_PARK_PARS_PARK_APP_DIR}")

#d:\Tools\ODB\odb-compiler\bin\odb.exe -d mysql --generate-query --generate-schema --std c++11 person.hxx
#d:\Tools\ODB\odb-compiler\bin\odb.exe --std c++11 --database mysql --generate-schema --generate-query --hxx-prologue "#include \"traits.hxx\""  --table-prefix mapping_ person.hxx