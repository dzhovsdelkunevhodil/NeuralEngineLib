cmake_minimum_required (VERSION 3.10)

include(FetchContent)

FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
#как я понял лучше
#использовать URL вместо GIT_REPOSITORY
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(DefineComponentTestMacro)

define_component_test_macro(Core)
define_component_test_macro(Backend)
define_component_test_macro(Utils)

include("${CMAKE_BINARY_DIR}/GeneratedAddTestMacros.cmake")

add_core_test(CoreTest core_test.cpp 10)
add_backend_test(BackendTest backend_test.cpp 10)
add_utils_test(UtilsTest utils_test.cpp 10)