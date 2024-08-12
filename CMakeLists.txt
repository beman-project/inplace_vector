# cmake-format: off
# /CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

cmake_minimum_required(VERSION 3.23)
project(
    InplaceVector
    VERSION 1.0.0
    DESCRIPTION "A dynamically-resizable vector with fixed capacity and embedded storage"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)
include(CTest)
add_subdirectory(src/Beman/InplaceVector)

if (BUILD_TESTING)
    add_subdirectory(src/Beman/InplaceVector/tests)
endif()