cmake_minimum_required(VERSION 3.19...3.20 FATAL_ERROR)

set(SOURCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/tests/test-app)

set(SRC ${SOURCE_ROOT_DIR}/testApp.cpp)

add_executable(testApp ${SRC})

target_include_directories(testApp PRIVATE
    $<BUILD_INTERFACE:${PROJECT_ROOT_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${PROJECT_ROOT_INCLUDE_DIR}>
)

if(SML_WINDOWS_SYSTEM)
    set(WIN_ENTRY_POINT sml-main)
endif()
target_link_libraries(testApp ${WIN_ENTRY_POINT} sml-system sml-video)
