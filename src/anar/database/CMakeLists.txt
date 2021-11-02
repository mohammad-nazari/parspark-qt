set(
        DATABASE_SOURCES
        i-database.cpp
        mysql/mysql-database.cpp
        database-factory.cpp
        s-database.cpp
)

add_library(
        Database
        SHARED
        ${DATABASE_SOURCES}
)
add_library(
        Anar::Database
        ALIAS
        Database
)
set_target_properties(
        Database
        PROPERTIES
        VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
        OUTPUT_NAME AnarDatabase
        DEFINE_SYMBOL Database_EXPORTS
)
target_link_libraries(
        Database
        PUBLIC
        Poco::Foundation
        odb
        ODB::MySQL
        serial
)