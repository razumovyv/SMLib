###############################################################################
# File with function definitions
###############################################################################

include(CMakeParseArguments)

function(sml_add_library target)


cmake_parse_arguments(
    TARGET
    "STATIC"
    ""
    "SOURCES"
    ${ARGN}
)
if(NOT "${TARGET_UNPARSED_ARGUMENTS}" STREQUAL "")

    message(FATAL_ERROR "Missing arguments: ${TARGET_UNPARSED_ARGUMENTS}")

endif()


if(TARGET_STATIC)

    add_library(${target} STATIC ${TARGET_SOURCES})

else()

    add_library(${target} ${TARGET_SOURCES})

endif()

 # define the export symbol of the module
 string(REPLACE "-" "_" NAME_UPPER "${target}")
 string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
 set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

 if(NOT THIS_STATIC)
    set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -Debug)
 else()
    set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -Static-Debug)
    set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -Static)
    set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -Static)
    set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -Static)
 endif()

 set_target_properties(${target} PROPERTIES FOLDER "SMLib")

 install(TARGETS ${target} EXPORT SMLibExports
         RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COMPONENT bin
         LIBRARY DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} COMPONENT bin
         ARCHIVE DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} COMPONENT lib
         CONFIGURATIONS Debug
        )
    
target_include_directories(${target}
                            PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            PRIVATE ${PROJECT_SOURCE_DIR}/src)

endfunction(sml_add_library )




