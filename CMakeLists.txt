# cmake-format: off
# /CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

cmake_minimum_required(VERSION 3.23)

project(
        beman.inplace_vector
        VERSION 1.0.0
        DESCRIPTION "A dynamically-resizable vector with fixed capacity and embedded storage"
        LANGUAGES CXX
)

include(CTest)
add_subdirectory(src/beman/inplace_vector)

if (BUILD_TESTING)
    add_subdirectory(src/beman/inplace_vector/tests)
endif ()
