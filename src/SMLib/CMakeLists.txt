cmake_minimum_required(VERSION 3.19...3.20 FATAL_ERROR)

include(${PROJECT_SOURCE_DIR}/cmake/functions.cmake)



if(${SML_BUILD_ENTRY_MODULE})
    add_subdirectory(${SML_SOURCCE_ROOT_DIR}/Entry)
endif(${SML_BUILD_ENTRY_MODULE})

if(${SML_BUILD_SYSTEM_MODULE})
    add_subdirectory(${SML_SOURCCE_ROOT_DIR}/System)
endif(${SML_BUILD_SYSTEM_MODULE})

if(${SML_BUILD_VIDEO_MODULE})
    add_subdirectory(${SML_SOURCCE_ROOT_DIR}/Video)
endif(${SML_BUILD_VIDEO_MODULE})

