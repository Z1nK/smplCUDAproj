cmake_minimum_required(VERSION 3.16)

list (APPEND EXMPL_SOURCES
    main.cpp
    calculate.cpp
    calculate.h
    kernel.cu
    kernel.cuh
  )

set(EXECUTABLE_NAME CUDAexmpl)
# add the executable
add_executable(${EXECUTABLE_NAME} ${EXMPL_SOURCES})

target_include_directories(CUDAexmpl PUBLIC
                           "${PROJECT_BINARY_DIR}"
                        #    /usr/local/cuda-11.7/targets/x86_64-linux/include/
                            ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
                           )


