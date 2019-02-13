cmake_minimum_required(VERSION 3.13)
project(initPhase)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(solver solver.cc include/functions.cc)
add_executable(initial initial.cc include/functions.cc)

set_target_properties(solver initial PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS FALSE
        CXX_STANDARD_REQUIRED TRUE
        )


# this must be called before adding subdirectories that have tests


# users of the library do not need to build tests by default; they are likely
# only interested in installing headers and cmake files
option(IT515R_ENABLE_TESTING "enable testing for solver" OFF)

if(IT515R_ENABLE_TESTING)
    # this must be called before adding subdirectories that have tests
    enable_testing()

    add_subdirectory(test)
endif()

