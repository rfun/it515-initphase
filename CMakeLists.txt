cmake_minimum_required(VERSION 3.12)
project(phase5)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(solver solver.cc include/functions.cc)
add_executable(initial initial.cc include/functions.cc)

find_package(OpenMP)
add_executable(openmp openmp.cc include/functions.cc)


if(OpenMP_CXX_FOUND)
    target_link_libraries(openmp PUBLIC OpenMP::OpenMP_CXX)
endif()

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

