# cmake-format: off
# /CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

cmake_minimum_required(VERSION 3.23)

project(
    beman.inplace_vector
    VERSION 1.0.0
    DESCRIPTION
        "A dynamically-resizable vector with fixed capacity and embedded storage"
    LANGUAGES CXX
)

# [CMAKE.SKIP_TESTS]
option(
    BEMAN_INPLACE_VECTOR_BUILD_TESTS
    "Enable building tests and test infrastructure. Default: ON. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

include(GNUInstallDirs)

add_library(beman.inplace_vector INTERFACE)
# [CMAKE.LIBRARY_ALIAS]
add_library(beman::inplace_vector ALIAS beman.inplace_vector)

target_include_directories(
    beman.inplace_vector
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Install the InplaceVector library to the appropriate destination
install(
    TARGETS beman.inplace_vector
    EXPORT ${TARGETS_EXPORT_NAME}
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}
)

# Install the header files to the appropriate destination
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}
    FILES_MATCHING
    PATTERN
    "${CMAKE_CURRENT_SOURCE_DIR}/include/beman/inplace_vector/inplace_vector.hpp"
)

if(BEMAN_INPLACE_VECTOR_BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests/beman/inplace_vector)
endif()
