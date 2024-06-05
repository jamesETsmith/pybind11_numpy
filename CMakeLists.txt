#
# Preamble
#
cmake_minimum_required(VERSION 3.25)

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

#
# Build setup
#
find_package(OpenMP)

#
# PyBind11
#
pybind11_add_module(pybind11_numpy
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/numpy_interface.cpp)
target_link_libraries(pybind11_numpy PUBLIC pybind11::headers)

if(OpenMP_CXX_FOUND)
  target_link_libraries(pybind11_numpy PUBLIC OpenMP::OpenMP_CXX)
endif()
