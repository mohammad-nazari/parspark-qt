cmake_minimum_required(VERSION 3.0)

project(libodb VERSION 2.4.0 LANGUAGES CXX)
if (WIN32)
    set(
            PLATFORM_SOURCES
            odb/details/win32/exceptions.cxx
            odb/details/win32/init.cxx
            odb/details/win32/once.cxx
            odb/details/win32/thread.cxx
            odb/details/win32/tls.cxx
            odb/details/win32/condition.cxx
            odb/details/win32/dll.cxx
    )
else ()
    set(
            PLATFORM_SOURCES
            odb/details/posix/exceptions.cxx
            odb/details/posix/thread.cxx
    )
endif ()

set(
        ODB_SOURCES
        odb/database.cxx
        odb/exceptions.cxx
        odb/lazy-ptr-impl.cxx
        odb/prepared-query.cxx
        odb/query-dynamic.cxx
        odb/result.cxx
        odb/schema-catalog.cxx
        odb/section.cxx
        odb/session.cxx
        odb/statement.cxx
        odb/statement-processing.cxx
        odb/tracer.cxx
        odb/transaction.cxx
        odb/vector-impl.cxx
        odb/callback.cxx
        odb/connection.cxx
        odb/details/lock.cxx
        odb/details/mutex.cxx
        odb/details/buffer.cxx
        odb/details/condition.cxx
        odb/details/shared-ptr/base.cxx
        ${PLATFORM_SOURCES}
)

add_library(
        ${PROJECT_NAME}
        SHARED
        ${ODB_SOURCES}
)