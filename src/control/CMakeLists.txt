find_package(Qt5 COMPONENTS Core Sql SerialPort REQUIRED)
set(SOURCES
   ${SOURCES}
   ${CMAKE_SOURCE_DIR}/src/control/base-controller.cpp
   ${CMAKE_SOURCE_DIR}/src/control/login-controller.cpp
   ${CMAKE_SOURCE_DIR}/src/control/settings-controller.cpp
)
add_library(control
   ${SOURCES}
   )
target_link_libraries(control
  PRIVATE
 Qt5::Core
 Qt5::Sql
 Qt5::SerialPort
 service
 model
)
