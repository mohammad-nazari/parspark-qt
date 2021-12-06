cmake_minimum_required(VERSION 3.10)

project(odb-mysql VERSION 2.4.0 LANGUAGES CXX)

set(ODB_PROJECT_NAME                   ODB)
set(ODB_MYSQL_LIB_ALIAS_NAME           MySQL)

set(
        ODB_MYSQL_SOURCES
        odb/mysql/connection-factory.cxx
        odb/mysql/database.cxx
        odb/mysql/enum.cxx
        odb/mysql/error.cxx
        odb/mysql/exceptions.cxx
        odb/mysql/prepared-query.cxx
        odb/mysql/query.cxx
        odb/mysql/query-const-expr.cxx
        odb/mysql/query-dynamic.cxx
        odb/mysql/simple-object-statements.cxx
        odb/mysql/statement.cxx
        odb/mysql/statements-base.cxx
        odb/mysql/tracer.cxx
        odb/mysql/traits.cxx
        odb/mysql/transaction.cxx
        odb/mysql/transaction-impl.cxx
        odb/mysql/connection.cxx
        odb/mysql/details/options.cxx
        )

add_library(
        ${PROJECT_NAME}
        SHARED
        ${ODB_MYSQL_SOURCES}
)
add_library(${ODB_PROJECT_NAME}::${ODB_MYSQL_LIB_ALIAS_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        odb
        mysql
)