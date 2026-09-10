cmake_minimum_required(VERSION 3.10)
project(AddLib)
project(CalcLib)

find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(addlib add_bindings.cpp add.cpp)
pybind11_add_module(calclib add_bindings.cpp add.cpp multiply.cpp subtract.cpp divide.cpp)
