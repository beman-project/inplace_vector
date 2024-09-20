# cmake-format: off
# src/beman/inplace_vector/CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on
# Add the beman.inplace_vector library
add_library(beman.inplace_vector STATIC inplace_vector.cpp)
target_compile_features(beman.inplace_vector PRIVATE cxx_std_23)

# Include GNU install directories module
include(GNUInstallDirs)

# Add the current source directory to the Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Set the target Include directories for the InplaceVector library
target_include_directories(
        beman.inplace_vector
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
)

# Install the InplaceVector library to the appropriate destination
install(
        TARGETS beman.inplace_vector
        EXPORT ${TARGETS_EXPORT_NAME}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Convert the project name to lower case
string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_LOWER_PROJECT_NAME)

# Install the header files to the appropriate destination
install(
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_LOWER_PROJECT_NAME}
        FILES_MATCHING
        PATTERN "../../../include/beman/inplace_vector/inplace_vector.hpp"
)

# Link libraries to the beman.inplace_vector target
target_link_libraries(beman.inplace_vector)
