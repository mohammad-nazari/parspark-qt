set(
        INTERFACE_SOURCES
        a-jsonable.cpp
)

add_library(
        Interface
        SHARED
        ${INTERFACE_SOURCES}
)
add_library(
        Anar::Interface
        ALIAS
        Interface
)
set_target_properties(
        Interface
        PROPERTIES
        VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
        OUTPUT_NAME AnarInterface
        DEFINE_SYMBOL Interface_EXPORTS
)
target_link_libraries(
        Interface
        PUBLIC
        Poco::Foundation
        odb
        ODB::MySQL
        serial
)