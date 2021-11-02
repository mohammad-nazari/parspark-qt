set(
        CONTROLLER_SOURCES
        controller.cpp
        common-controller.cpp
)

add_library(
        Controller
        SHARED
        ${CONTROLLER_SOURCES}
)
add_library(
        Anar::Controller
        ALIAS
        Controller
)
set_target_properties(
        Controller
        PROPERTIES
        VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
        OUTPUT_NAME AnarController
        DEFINE_SYMBOL Controller_EXPORTS
)
target_link_libraries(
        Controller
        PUBLIC
        Poco::Foundation
        odb
        ODB::MySQL
        serial
        Anar::Service
)