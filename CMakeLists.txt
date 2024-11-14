# cmake-format: off
# /CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

set(CMAKE_SKIP_TEST_ALL_DEPENDENCY FALSE)

cmake_minimum_required(VERSION 3.25...3.31)

project(
    beman_inplace_vector
    VERSION 1.0.0
    DESCRIPTION "A dynamically-resizable vector with fixed capacity and embedded storage"
    LANGUAGES CXX
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds are not allowed!")
endif()

option(INPLACE_VECTOR_BUILD_TESTING "Build tests" ${PROJECT_IS_TOP_LEVEL})

add_library(beman_inplace_vector INTERFACE)
add_library(beman::beman_inplace_vector ALIAS beman_inplace_vector)

target_sources(
    beman_inplace_vector
    PUBLIC FILE_SET
           inplace_vector_public_headers
           TYPE
           HEADERS
           BASE_DIRS
           ${CMAKE_CURRENT_SOURCE_DIR}/include
           FILES
           "${CMAKE_CURRENT_SOURCE_DIR}/include/beman/inplace_vector/inplace_vector.hpp"
)
set_target_properties(beman_inplace_vector PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

block()
# copied from execution26:
set(TARGET_NAME beman_inplace_vector)
set(TARGET_NAMESPACE beman)
# set(TARGET_PREFIX ${TARGET_NAMESPACE}.${TARGET_NAME}) # FIXME: not used yet? CK
# set(TARGET_LIBRARY ${PROJECT_NAME})
# set(TARGET_ALIAS ${TARGET_LIBRARY}::${TARGET_LIBRARY})
set(TARGET_PACKAGE_NAME ${PROJECT_NAME}-config)
set(TARGETS_EXPORT_NAME ${PROJECT_NAME}-targets)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

# Install the InplaceVector library to the appropriate destination
install(
    TARGETS beman_inplace_vector
    EXPORT ${TARGETS_EXPORT_NAME}
    FILE_SET inplace_vector_public_headers
    # DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(EXISTS cmake/Config.cmake.in)
    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}-version.cmake VERSION ${CMAKE_PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
    )

    configure_package_config_file(
        cmake/Config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
    )

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}.cmake
                  ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}-version.cmake DESTINATION ${INSTALL_CONFIGDIR}
    )

    install(EXPORT ${TARGETS_EXPORT_NAME} FILE ${TARGETS_EXPORT_NAME}.cmake DESTINATION "${INSTALL_CONFIGDIR}"
            NAMESPACE beman::
    )

set(CPACK_GENERATOR TGZ)
include(CPack)

endif()
endblock()

if(INPLACE_VECTOR_BUILD_TESTING)
    enable_testing()
    # TODO(CK): why not simply use subdir ./tests
    add_subdirectory(src/beman/inplace_vector/tests)
endif()
