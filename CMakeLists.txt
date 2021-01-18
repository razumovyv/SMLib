# Main file CMakeLists.txt

cmake_minimum_required(VERSION 3.1...3.19)

# Set project name
project(SMLib
        VERSION 1.0.0
        DESCRIPTION "Simple Media Library"
        LANGUAGES C CXX)

# Run the cmake config script
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake)

set(PROJECT_ROOT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
        
configure_file( ${PROJECT_SOURCE_DIR}/cmake/Version.h.in
                ${PROJECT_ROOT_INCLUDE_DIR}/${PROJECT_NAME}/System/Version.h)