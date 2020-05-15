cmake_minimum_required(VERSION 3.5)

project(ParsPark LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(Qt5 COMPONENTS Core Quick LinguistTools Sql REQUIRED)

set(TS_FILES ParsPark_fa_IR.ts)
add_subdirectory(
   ${CMAKE_SOURCE_DIR}/src
   )
file(GLOB SOURCES
   ${CMAKE_SOURCE_DIR}/main.cpp
   ${CMAKE_SOURCE_DIR}/qml.qrc
   ${CMAKE_SOURCE_DIR}/icon.rc
)
if(ANDROID)
    add_library(ParsPark SHARED
       ${SOURCES}
    )
else()
    add_executable(ParsPark
       ${SOURCES}
    )
endif()

target_compile_definitions(ParsPark
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ParsPark
  PRIVATE
  Qt5::Core
  Qt5::Quick
  Qt5::Sql
  control
  service
  model
  settings
  view
  )

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
