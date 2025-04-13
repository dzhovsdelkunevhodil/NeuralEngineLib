macro(add_component name)
    add_library(${name} INTERFACE)
    target_include_directories(${name} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
    target_compile_features(${name} INTERFACE cxx_std_17)
    add_library(NeuralEngineLib::${name} ALIAS ${name})
endmacro()