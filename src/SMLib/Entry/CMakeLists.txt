cmake_minimum_required(VERSION 3.1...3.19)

if(SML_WINDOWS_SYSTEM)
    set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/MainWin32.cpp)
else()
    return()
endif()


add_library(sml-main STATIC ${SRC})

target_include_directories(sml-main PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} sge-main)

install(TARGETS sml-main EXPORT ${PROJECT_NAME}_targets
        CONFIGURATIONS Debug
        ARCHIVE DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

