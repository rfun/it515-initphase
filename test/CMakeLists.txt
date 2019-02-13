# This has the `catch_discover_tests` definition
include(catch/Catch.cmake)

# This library will help reduce compilation times
add_library(catch OBJECT main.cc)
target_compile_features(catch PUBLIC cxx_std_14)

# Creates a test executable
add_executable(test_solver solver_functions.cc $<TARGET_OBJECTS:catch> ../include/functions.cc)

# This integrates each TEST_CASE with CTest
catch_discover_tests(test_solver)
