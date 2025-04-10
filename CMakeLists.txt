﻿cmake_minimum_required (VERSION 3.10)

project(NeuralEngineLib VERSION 1.0.0 LANGUAGES C CXX )


###########22222222222222222##############
include(GNUInstallDirs)
###########22222222222222222##############

###########44444444444444444##############
option(BUILD_TESTS "Build tests" OFF)
###########44444444444444444##############

###########1111111111111111##############
option(NEURAL_ENGINE_USE_GPU "use gpu" OFF)
option(NEURAL_ENGINE_LOGGING "logging" OFF)

add_library(Core INTERFACE)
target_include_directories(Core INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
add_library(NeuralEngineLib::Core ALIAS Core)

add_library(Backend INTERFACE)
target_include_directories(Backend INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(Backend INTERFACE cxx_std_17)
add_library(NeuralEngineLib::Backend ALIAS Backend)

if (NEURAL_ENGINE_USE_GPU)
    target_compile_definitions(Backend INTERFACE NEURAL_ENGINE_USE_GPU=1)
else()
    target_compile_definitions(Backend INTERFACE NEURAL_ENGINE_USE_GPU=0)

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(Backend INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-O3>)
    endif()
endif()

add_library(Utils INTERFACE)
target_include_directories(Utils INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(Utils INTERFACE cxx_std_17)
add_library(NeuralEngineLib::Utils ALIAS Utils)

if (NEURAL_ENGINE_ENABLE_LOGGING)
    target_compile_definitions(Utils INTERFACE NEURAL_ENGINE_LOGGING=1)
endif()
###########1111111111111111##############

###########44444444444444444##############
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
###########44444444444444444##############

###########3333333333333333##############
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/NeuralEngineLibConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion
)
###########3333333333333333##############


###########555555555555555##############
add_subdirectory(src)
#не уверен надо ли CMakeLists в src/
#или надо было все в этот CMakeLists засунуть
add_subdirectory(packaging)


###########555555555555555##############


###########22222222222222222##############
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/cmake
)
                            
install(
    TARGETS Core Backend Utils
    EXPORT ${PROJECT_NAME}_Targets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT dev)

install(
    EXPORT ${PROJECT_NAME}_Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    COMPONENT dev)

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/NeuralEngineLib"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT dev
    FILES_MATCHING PATTERN "*.h")

install(
    FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    COMPONENT dev)

###########22222222222222222##############

