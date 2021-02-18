
set(HEADER_ROOT_DIR ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/Video)
set(SOURCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/Video)

set (SRC 
    ${SOURCE_ROOT_DIR}/Display.cpp
    ${SOURCE_ROOT_DIR}/DisplayImpl.h
    ${SOURCE_ROOT_DIR}/VideoMode.cpp
    ${SOURCE_ROOT_DIR}/MultiDisplay.cpp
    )

source_group("" FILES ${SRC})

if(SML_WINDOWS_SYSTEM)
    set(PLATFORM_SRC ${SOURCE_ROOT_DIR}/Win32/DisplayImpl.cpp)

    source_group("windows" FILE ${PLATORM_SRC})
endif()

sml_add_Library(sml-video SOURCES ${SRC} ${PLATFORM_SRC})

