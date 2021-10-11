cmake_minimum_required(VERSION 3.19)
project(pybind11_numpy LANGUAGES CXX)

find_package(OpenMP)

#
# PyBind11
#
add_subdirectory(${CMAKE_SOURCE_DIR}/external/pybind11)
pybind11_add_module(pybind11_numpy ${CMAKE_SOURCE_DIR}/src/numpy_interface.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(pybind11_numpy PUBLIC OpenMP::OpenMP_CXX)
endif()
