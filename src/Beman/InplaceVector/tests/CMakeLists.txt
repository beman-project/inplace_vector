# cmake-format: off
# src/Beman/InplaceVector/tests/CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

# Tests
add_executable(
        InplaceVectorTest.test)

target_sources(InplaceVectorTest.test PRIVATE InplaceVector.test.cpp)

target_link_libraries(InplaceVectorTest.test PRIVATE
        InplaceVector)


add_test(
        NAME InplaceVectorTest.test
        COMMAND InplaceVectorTest.test
)
