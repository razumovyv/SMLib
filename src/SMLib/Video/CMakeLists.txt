
set(HEADER_ROOT_DIR ${PROJECT_SOURCE_DIR}/include/SMLib/Display)
set(SOURCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/src/Display)

set (SRC ${SOURCE_ROOT_DIR}/Dispplay.cpp
         ${SOURCE_ROOT_DIR}/DisplayImpl.h
    )

source_group("" FILES ${SRC})

if(SML_WINDOWS_SYSTEM)
    set(PLATFORM_SRC ${SOURCE_ROOT_DIR}/Win32/DisaplyImpl.cpp)

    source_group("windows" FILE ${PLATORM_SRC})
endif()