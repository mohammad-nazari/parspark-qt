find_package(Qt5 COMPONENTS Core SerialPort REQUIRED)
set(SOURCES
   ${SOURCES}
   ${CMAKE_SOURCE_DIR}/src/service/base-service.cpp
   ${CMAKE_SOURCE_DIR}/src/service/s-settings.cpp
   ${CMAKE_SOURCE_DIR}/src/service/serial-port.cpp
)
add_library(service
   ${SOURCES}
   )
target_link_libraries(service
   PRIVATE
   Qt5::Core
   Qt5::SerialPort
)
