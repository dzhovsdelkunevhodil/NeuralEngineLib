cmake_minimum_required (VERSION 3.10)
include(FetchContent)
FetchContent_Declare(boost_math
    URL https://github.com/boostorg/math/archive/refs/tags/boost-1.87.0.zip
)
FetchContent_MakeAvailable(boost_math)

add_library(Boost::math ALIAS boost_math)

add_library(CoreGelu STATIC core.cpp)

target_include_directories(CoreGelu PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(CoreGelu PRIVATE $<LINK_ONLY:Boost::math>)

target_link_libraries(CoreGelu INTERFACE Core)

install(TARGETS CoreGelu
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT lib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT lib
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT lib)