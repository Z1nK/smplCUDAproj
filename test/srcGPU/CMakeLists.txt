# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(EXECUTABLE_NAME runTestsGPU)
# Link runTests with what we want to test and the GTest and pthread library
add_executable(${EXECUTABLE_NAME} tests.cu)

target_include_directories(${EXECUTABLE_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                        #    /usr/local/cuda-11.7/targets/x86_64-linux/include/
                            ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
                           )

target_link_libraries(${EXECUTABLE_NAME} ${GTEST_LIBRARIES} pthread)