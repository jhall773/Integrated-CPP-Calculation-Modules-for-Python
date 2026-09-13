# Introduction
I created this repository while teaching myself how to build **Python extension modules in C++ using pybind11 and CMake**. The goal isn’t to provide a production‑ready package, but to document the steps, structure, and patterns that helped me understand how Python can call into C++ for faster numerical operations. If you’re learning the same tools, feel free to explore or reuse the examples here.

# Note on CMakeLists.txt
The CMakeLists.txt shown in this repository is for **Linux**. 

**For Windows, some of CMake may not default to the C++ 17 standard. please use this CMakeLists.txt specification below**:
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(CalcLib)

set(pybind11_DIR "C:/Users/joebu/pybind11_install/share/cmake/pybind11")
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(calclib add_bindings.cpp add.cpp multiply.cpp subtract.cpp divide.cpp)

# Project Structure
```
Python_and_CPP_dev/
│
├── CMakeLists.txt
├── requirements.txt
├── test.py
│
├── calculations.hpp
├── add.cpp
├── subtract.cpp
├── multiply.cpp
├── divide.cpp
│
├── add_bindings.cpp
│
└── build/
    └── calclib.cpython-*.so
```
## Notes on Structure:
- **Source files (.cpp)** contain the actual C++ logic.

- **Header file (calculations.hpp)** declares the functions so multiple modules can include them.

- **Bindings file (add_bindings.cpp)** is where pybind11 exposes C++ functions to Python.

- **CMakeLists.txt** controls how everything is compiled.

**The 'build/' folder is generated — it’s not meant to be committed to GitHub. You can generate the 'calclibc.python-*.so' Python module (library) file yourself using the CMakeLists.txt**

**test.py** is the Python entry point that loads the compiled modules and runs example operations.

# How to Build This Project
If you want to try it yourself or adapt it for your own learning, here are the basic steps I used:

## 1. Install the Python dependencies
The project uses pybind11, and the correct version is listed in requirements.txt.
Install it with:

pip install -r requirements.txt

## 2. Create a build directory and run CMake
Note: For Windows, you will likely need to follow these steps while using the "Visual Studio 2026 Developer Command Prompt". I used "v18.8.2".
From the project’s root folder (the one containing CMakeLists.txt and the Python/C++ **'.py' and '.cpp'** source files), create a build folder and configure the project:

mkdir build

cd build

cmake .. (Linux)
cmake .. -G "Ninja" (Windows)

cmake --build .
ninja (Windows)

This compiles the C++ code and produces Python extension modules (.so files) inside the build/ directory.

## 3. Run the Python test script
Go back to the project root (the folder containing test.py) and run:

python3 test.py

The script imports the compiled modules from the build/ directory and runs a few example operations.
On Windows, you will have to run the python script from the "Visual Studio 2026 Developer Command Prompt". I used "v18.8.2".
