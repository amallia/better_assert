EXECUTE_PROCESS(COMMAND git submodule update --init
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
                OUTPUT_QUIET
        )

if(NOT TARGET gtest)
    add_subdirectory(googletest EXCLUDE_FROM_ALL)
endif()
