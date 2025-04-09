mkdir build cd build

cmake .. -DCMAKE_INSTALL_PREFIX:PATH="path\install" -DNEURAL_ENGINE_ENABLE_LOGGING=1 -DNEURAL_ENGINE_USE_GPU=1

cmake --build . --config Release --target install

////////////////////использование////////////////

cmake .. -DCMAKE_PREFIX_PATH="path\NeuralEngineLib"

cmake --build .

////////////////тесты////////////
cmake .. -DCMAKE_INSTALL_PREFIX:PATH="C:\NeuralEngineLib" -DNEURAL_ENGINE_ENABLE_LOGGING=1 -DNEURAL_ENGINE_USE_GPU=1 -DBUILD_TESTS=1

ctest -C Release