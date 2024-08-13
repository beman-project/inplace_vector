# cmake-format: off
# src/Beman/InplaceVector/CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on
# Add the InplaceVector library
add_library(InplaceVector STATIC inplacevector.cpp)

# Include GNU install directories module
include(GNUInstallDirs)

# Add the current source directory to the Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Set the target Include directories for the InplaceVector library
target_include_directories(
        InplaceVector
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../Include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_LOWER_PROJECT_NAME}>
)

# Install the InplaceVector library to the appropriate destination
install(
        TARGETS InplaceVector
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
        PATTERN "*.hpp"
)

# Link libraries to the InplaceVector target
target_link_libraries(InplaceVector)