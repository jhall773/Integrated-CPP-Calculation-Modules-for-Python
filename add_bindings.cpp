#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "calculations.hpp"

namespace py = pybind11;

PYBIND11_MODULE(calclib, m) {
    m.def("add", &add, "Add two integers");
    m.def("sub", &sub, "Subtract two integers");
    m.def("mult", &mult, "Multiply two decimal numbers");
    m.def("divide", &divide, "Divide two decimal numbers"); 
}
