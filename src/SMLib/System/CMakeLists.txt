
set(HEADER_ROOT_DIR ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/System)
set(SOURCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/System)

set(SRC
    ${HEADER_ROOT_DIR}/NoneCopyable.h
    ${SOURCE_ROOT_DIR}/NoneCopyable.cpp
    ${HEADER_ROOT_DIR}/String.h
    ${SOURCE_ROOT_DIR}/String.cpp
)

source_group("" FILES ${SRC})

#if(SML_WINDOWS_SYSTEM)
#    set(PLATFORM_SRC ${SOURCE_ROOT_DIR}/Win32/DisplayImpl.cpp)
#
#    source_group("windows" FILE ${PLATORM_SRC})
#endif()

sml_add_Library(sml-system SOURCES ${SRC})
