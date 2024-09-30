cmake_minimum_required(VERSION 3.19...3.20 FATAL_ERROR)

set(SOURCE_ROOT_DIR ${PROJECT_SOURCE_DIR}/tests/test-app)

set(SRC ${SOURCE_ROOT_DIR}/testApp.cpp)

add_executable(testApp ${SRC})

target_link_libraries(testApp PUBLIC sml-main sml-system sml-video)
