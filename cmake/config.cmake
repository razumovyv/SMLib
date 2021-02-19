###############################################################################
# Main cmake config file
###############################################################################


set(PROJECT_ROOT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# Set the prefix for install directory
set(CMAKE_INSTALL_PREFIX 
    ${PROJECT_SOURCE_DIR}/out/install)
# Executable files and library files be created in to once directory
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib)

# Disable C++ extensions
if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# Detect th operating system
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(SML_WINDOWS_SYSTEM 1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(SML_LINUX_SYSTEM 1)
else()
    message(FATAL_ERROR "SMLib do not support your operating system")
    return()
endif()
