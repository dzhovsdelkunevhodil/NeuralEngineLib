
macro(add_core_test test_name test_source timeout)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE NeuralEngineLib::Core gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_tests_properties(${test_name} PROPERTIES TIMEOUT ${timeout})
endmacro()

macro(add_backend_test test_name test_source timeout)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE NeuralEngineLib::Backend gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_tests_properties(${test_name} PROPERTIES TIMEOUT ${timeout})
endmacro()


macro(add_utils_test test_name test_source timeout)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE NeuralEngineLib::Utils gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_tests_properties(${test_name} PROPERTIES TIMEOUT ${timeout})
endmacro()
