# cmake-format: off
# src/beman/inplace_vector/tests/CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

# Tests
add_executable(
        beman.inplace_vector.test inplace_vector.test.cpp)

target_link_libraries(beman.inplace_vector.test PRIVATE
        beman.inplace_vector)

target_compile_features(beman.inplace_vector PRIVATE cxx_std_23)

add_test(
        NAME beman.inplace_vector.test
        COMMAND beman.inplace_vector.test
)
