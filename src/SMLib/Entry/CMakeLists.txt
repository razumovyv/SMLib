cmake_minimum_required(VERSION 3.19...3.20 FATAL_ERROR)

if(SML_WINDOWS_SYSTEM)
    set(SRC ${SRC} ${CMAKE_CURRENT_SOURCE_DIR}/MainWin32.cpp)
else()
    return()
endif()

sml_add_library(sml-main STATIC SOURCES ${SRC})