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
set(CMAKE_PROJECT_VERSION_MAJOR 1)
set(CMAKE_PROJECT_VERSION_MINOR 0)
set(CMAKE_PROJECT_VERSION_PATCH 0)
set(CMAKE_PROJECT_VERSION_TWEAK 0)

# Creating a version header file
configure_file( ${PROJECT_SOURCE_DIR}/cmake/Version.h.in
                ${PROJECT_ROOT_INCLUDE_DIR}/${PROJECT_NAME}/Version.h)

set(SML_SOURCCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME})
#For Debug
set(SML_SHARED_LIBS 1)
option(SML_BUILD_VIDEO_MODULE "Set ON if want build video module" ON)
option(SML_BUILD_ENTRY_MODULE "Set ON if want build entry point" ON)

add_subdirectory(${SML_SOURCCE_ROOT_DIR})
