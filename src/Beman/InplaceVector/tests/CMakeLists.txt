# cmake-format: off
# src/Beman/InplaceVector/tests/CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

# Tests
add_executable(
        Beman.InplaceVectorTest.test InplaceVector.test.cpp)

target_sources(Beman.InplaceVectorTest.test PRIVATE InplaceVector.test.cpp)

target_link_libraries(Beman.InplaceVectorTest.test PRIVATE
        Beman.InplaceVector)


add_test(
        NAME InplaceVectorTest.test
        COMMAND InplaceVectorTest.test
)
