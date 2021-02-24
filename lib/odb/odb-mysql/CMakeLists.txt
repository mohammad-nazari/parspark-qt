cmake_minimum_required(VERSION 3.10)

project(odb-mysql VERSION 2.4.0 LANGUAGES CXX)

set(ODB_PROJECT_NAME                   ODB)
set(ODB_MYSQL_LIB_ALIAS_NAME           MySQL)

set(sources
        odb/mysql/connection.hxx
        odb/mysql/connection.ixx
        odb/mysql/connection-factory.cxx
        odb/mysql/connection-factory.hxx
        odb/mysql/container-statements.hxx
        odb/mysql/container-statements.txx
        odb/mysql/database.cxx
        odb/mysql/database.hxx
        odb/mysql/database.ixx
        odb/mysql/enum.cxx
        odb/mysql/enum.hxx
        odb/mysql/error.cxx
        odb/mysql/error.hxx
        odb/mysql/exceptions.cxx
        odb/mysql/exceptions.hxx
        odb/mysql/forward.hxx
        odb/mysql/mysql.hxx
        odb/mysql/mysql-types.hxx
        odb/mysql/no-id-object-result.hxx
        odb/mysql/no-id-object-result.txx
        odb/mysql/no-id-object-statements.hxx
        odb/mysql/no-id-object-statements.txx
        odb/mysql/polymorphic-object-result.hxx
        odb/mysql/polymorphic-object-result.txx
        odb/mysql/polymorphic-object-statements.hxx
        odb/mysql/polymorphic-object-statements.txx
        odb/mysql/prepared-query.cxx
        odb/mysql/prepared-query.hxx
        odb/mysql/query.cxx
        odb/mysql/query.hxx
        odb/mysql/query.ixx
        odb/mysql/query.txx
        odb/mysql/query-const-expr.cxx
        odb/mysql/query-dynamic.cxx
        odb/mysql/query-dynamic.hxx
        odb/mysql/query-dynamic.ixx
        odb/mysql/query-dynamic.txx
        odb/mysql/section-statements.hxx
        odb/mysql/section-statements.txx
        odb/mysql/simple-object-result.hxx
        odb/mysql/simple-object-result.txx
        odb/mysql/simple-object-statements.cxx
        odb/mysql/simple-object-statements.hxx
        odb/mysql/simple-object-statements.ixx
        odb/mysql/simple-object-statements.txx
        odb/mysql/statement.cxx
        odb/mysql/statement.hxx
        odb/mysql/statement-cache.hxx
        odb/mysql/statement-cache.txx
        odb/mysql/statements-base.cxx
        odb/mysql/statements-base.hxx
        odb/mysql/tracer.cxx
        odb/mysql/tracer.hxx
        odb/mysql/traits.cxx
        odb/mysql/traits.hxx
        odb/mysql/traits-calls.hxx
        odb/mysql/transaction.cxx
        odb/mysql/transaction.hxx
        odb/mysql/transaction.ixx
        odb/mysql/transaction-impl.cxx
        odb/mysql/transaction-impl.hxx
        odb/mysql/transaction-impl.ixx
        odb/mysql/version.hxx
        odb/mysql/view-result.hxx
        odb/mysql/view-result.txx
        odb/mysql/view-statements.hxx
        odb/mysql/view-statements.txx
        odb/mysql/auto-handle.hxx
        odb/mysql/binding.hxx
        odb/mysql/config.h.in
        odb/mysql/connection.cxx
        odb/mysql/details/export.hxx
        odb/mysql/details/options.cli
        odb/mysql/details/options.cxx
        odb/mysql/details/options.hxx
        odb/mysql/details/options.ixx
        odb/mysql/details/config.hxx
        odb/mysql/details/conversion.hxx
        )

add_library(
        ${PROJECT_NAME}
        SHARED
        ${sources}
)
add_library(${ODB_PROJECT_NAME}::${ODB_MYSQL_LIB_ALIAS_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        odb
        mysql
)