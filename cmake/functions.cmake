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
    message("name upper: ${NAME_UPPER}")
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORT)

    if(BUILD_SHARED_LIBS AND (NOT THIS_STATIC))
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -debug)
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -static-debug)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -static)
        set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -static)
        set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -static)
    endif()

    set_target_properties(${target} PROPERTIES FOLDER "SMLib")

    install(TARGETS ${target} EXPORT SMLibExports
        RUNTIME DESTINATION ${SML_INSTALL_ROOT_DIR}/bin COMPONENT bin
        LIBRARY DESTINATION ${SML_INSTALL_ROOT_DIR}/lib COMPONENT bin
        ARCHIVE DESTINATION ${SML_INSTALL_ROOT_DIR}/lib COMPONENT lib
        CONFIGURATIONS Debug
    )

    target_include_directories(${target}
        PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        PRIVATE ${PROJECT_SOURCE_DIR}/src)

endfunction(sml_add_library)



