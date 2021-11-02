set(
        SERVICE_SOURCES
        service.cpp
        model-binding/json/json-parser.cpp
        binary.cpp
        string.cpp
        printer.cpp
        serial-port.cpp
)

add_library(
        Service
        SHARED
        ${SERVICE_SOURCES}
)
add_library(
        Anar::Service
        ALIAS
        Service
)
set_target_properties(
        Service
        PROPERTIES
        VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
        OUTPUT_NAME AnarService
        DEFINE_SYMBOL Service_EXPORTS
)
target_link_libraries(
        Service
        PUBLIC
        Poco::Foundation
        odb
        ODB::MySQL
        serial
)