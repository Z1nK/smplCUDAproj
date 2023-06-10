cmake_minimum_required(VERSION 3.16)

#Check if CUDA is available
include(CheckLanguage)
check_language(CUDA)

# set the project name and versiond
project(CUDAexmpl VERSION 1.0 LANGUAGES CXX CUDA)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CUDA_ARCHITECTURES "86")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add sub directory
add_subdirectory(project/src)
add_subdirectory(test/srcCPU)
add_subdirectory(test/srcGPU)





