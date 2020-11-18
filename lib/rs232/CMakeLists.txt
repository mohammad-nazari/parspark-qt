cmake_minimum_required(VERSION 3.16)

project(${ANAR_RS232_LIB})

add_library(
        ${PROJECT_NAME}
        SHARED
        rs232.c
)