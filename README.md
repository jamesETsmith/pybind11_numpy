# Overview
![Build](https://github.com/jamesETsmith/pybind11_numpy/actions/workflows/cmake.yml/badge.svg) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/b63545b9023a466e961b4aeed9c12806)](https://www.codacy.com/gh/jamesETsmith/pybind11_numpy/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jamesETsmith/pybind11_numpy&amp;utm_campaign=Badge_Grade)

This a set of simple examples for using `pybind11` with NumPy arrays focusing specifically on passing arrays from Python to C++, modifying them, and then using them some more in Python.

# Software Prerequisites
- CMake >= 3.19
- C++ compiler (`-std=c++11` or later)
- Python 3.X
  - pytest
  - pybind11 (included in this package)

# Install and Test

```bash
git clone --recursive https://github.com/jamesETsmith/pybind11_numpy.git
cd pybind11_numpy
CXX=YOUR_C++_COMPILER cmake -B build
cmake --build build
PYTHONPATH=build/:$PYTHONPATH pytest -v test
```
