
set(_TEST_MACRO_FILE "${CMAKE_BINARY_DIR}/GeneratedAddTestMacros.cmake")

file(WRITE "${_TEST_MACRO_FILE}" "")

macro(define_component_test_macro component_name)
    string(TOLOWER "${component_name}" lower_component_name)
    set(macro_name add_${lower_component_name}_test)
    set(lib_target NeuralEngineLib::${component_name})

    set(full_macro "
macro(${macro_name} test_name test_source timeout)
    add_executable(\${test_name} \${test_source})
    target_link_libraries(\${test_name} PRIVATE ${lib_target} gtest_main)
    add_test(NAME \${test_name} COMMAND \${test_name})
    set_tests_properties(\${test_name} PROPERTIES TIMEOUT \${timeout})
endmacro()
")


    file(APPEND "${_TEST_MACRO_FILE}" "${full_macro}\n")
endmacro()


