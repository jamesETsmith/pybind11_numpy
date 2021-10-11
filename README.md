# Overview

This a set of simple examples for using `pybind11` with NumPy arrays focusing specifically on passing arrays from Python to C++, modifying them, and then using them some more in Python.

# Software Prerequisites
- CMake >= 3.19
- C++ compiler (`-std=c++11` or later)
- Python 3.X
  - pytest
  - pybind11 (included in this package)

# Install and Test

```bash
git clone --recursive FIXME
cd pybind11_numpy
CXX=YOUR_C++_COMPILER cmake -B build
cmake --build build
PYTHONPATH=build/:$PYTHONPATH pytest -v test
```