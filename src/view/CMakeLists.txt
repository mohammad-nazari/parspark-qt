find_package(Qt5 COMPONENTS Core Quick LinguistTools Sql REQUIRED)
include_directories(${CMAKE_SOURCE_DIR})
set(SOURCES
   ${SOURCES}
   ${CMAKE_SOURCE_DIR}/src/view/login/login-view.cpp
   ${CMAKE_SOURCE_DIR}/src/view/settings/settings-view.cpp
)
add_library(view
   ${SOURCES}
   )
target_link_libraries(view
  PRIVATE
 Qt5::Core
 model
 control
)
