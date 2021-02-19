###############################################################################
# Main file CMakeLists.txt
###############################################################################
cmake_minimum_required(VERSION 3.19...3.20 FATAL_ERROR)

# Set project name
project(SMLib
        DESCRIPTION "Simple Media Library"
        LANGUAGES C CXX)

# Run the cmake config script
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake)

# Set project version
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION_TWEAK 0)

# Creating a version header file
configure_file( ${PROJECT_SOURCE_DIR}/cmake/Version.h.in
                ${PROJECT_ROOT_INCLUDE_DIR}/${PROJECT_NAME}/Version.h)

set(SML_SOURCCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME})
set(SML_INSTALL_ROOT_DIR 
    ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

#For Debug

set(BUILD_SHARED_LIBS ON)
set(SML_BUILD_ENTRY_MODULE ON)
set(SML_BUILD_SYSTEM_MODULE ON)
set(SML_BUILD_VIDEO_MODULE ON)
message("SML_BUILD_VIDEO_MODULE: ${SML_BUILD_VIDEO_MODULE}")

message("RUNTIME_OUTPUT_DIRECTORY:>>${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("LIBRARY_OUTPUT_DIRECTORY:>>${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("ARCHIVE_OUTPUT_DIRECTORY:>>${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("CMAKE_INSTALL_NAME_DIR:>>${CMAKE_INSTALL_NAME_DIR}")

add_subdirectory(${SML_SOURCCE_ROOT_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/tests/test-app)
