# Detect th operating system
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(SGE_OS_WINDOWS 1)
else()
    return()
endif()

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# Set the prefix for install directory
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out/install/${PROJECT_NAME})