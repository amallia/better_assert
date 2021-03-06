cmake_minimum_required(VERSION 3.0)

if (NOT CMAKE_BUILD_TYPE)
        message(STATUS "No build type selected, default to Release")
        set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()
MESSAGE( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE} )

project(better_assert)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CXX_COMPILER_VERSION VERSION_LESS 4.7)
        message(STATUS "GCC version must be at least 4.7!")
    endif()
    set (CMAKE_CXX_FLAGS_RELEASE "-Wall -Wcast-align -Ofast -lm  -DNDEBUG -std=c++11 -DHAVE_CXX0X -march=native")
    set (CMAKE_CXX_FLAGS_DEBUG   "-Wall -Wcast-align -ggdb  -lm  -std=c++11 -DHAVE_CXX0X -march=native")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (CXX_COMPILER_VERSION VERSION_LESS 4.2.1)
        message(STATUS  "Clang version must be at least 4.2.1!" )
    endif()
    set (CMAKE_CXX_FLAGS_RELEASE "-Wall -Wcast-align -O3 -DNDEBUG -std=c++11 -DHAVE_CXX0X -msse4.1 -march=native")
    set (CMAKE_CXX_FLAGS_DEBUG   "-Wall -Wcast-align -ggdb  -std=c++11 -DHAVE_CXX0X -msse4.1 -march=native")
else ()
    message(FATAL_ERROR "Please, use GCC or Clang compiler!")
endif()

# if (USE_SANITIZERS)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
# endif ()


add_subdirectory(external)

include_directories(include)
add_library(better_assert INTERFACE)
target_include_directories(better_assert INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

enable_testing()
add_subdirectory(test)
