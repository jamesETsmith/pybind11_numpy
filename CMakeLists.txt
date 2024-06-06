#
# Preamble
#
cmake_minimum_required(VERSION 3.29)

set(CMAKE_EXPORT_COMPILE_COMMANDS
    TRUE
    CACHE BOOL "Export compile commands to build directory" FORCE)

#
# Dependencies
#
include(cmake/CPM.cmake)
cpmaddpackage("gh:pybind/pybind11@2.11.1")
cpmaddpackage("gh:kokkos/mdspan#b885a2c60ad42f9e1aaa0d317a38105b950cbed0")

#
# Project setup
#

project(pybind11_numpy LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Build setup
#
find_package(OpenMP REQUIRED)

#
# PyBind11
#

# Numpy PyBind11 module
pybind11_add_module(pybind11_numpy
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/numpy_interface.cpp)
target_link_libraries(pybind11_numpy PUBLIC pybind11::headers)
target_link_libraries(pybind11_numpy PUBLIC OpenMP::OpenMP_CXX)

# Numpy -> std::mdspan module
pybind11_add_module(pybind11_mdspan
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/mdspan_interface.cpp)
target_link_libraries(pybind11_mdspan PUBLIC pybind11::headers mdspan)
target_link_libraries(pybind11_mdspan PUBLIC OpenMP::OpenMP_CXX)
