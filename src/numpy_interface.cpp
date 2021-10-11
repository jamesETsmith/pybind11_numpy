#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void change_vector(py::array_t<double> array) {
  auto v = array.mutable_unchecked<1>();
  v(0) += 1;
  return;
}

void change_4D_tensor(py::array_t<double> array) {
  auto v = array.mutable_unchecked<4>();
  v(0, 0, 0, 0) += 1;
  return;
}

void contract_4D_tensors(py::array_t<double> array1, py::array_t<double> array2,
                         py::array_t<double> array3) {
  auto t1 = array1.mutable_unchecked<4>(); // Mandate 4 dims
  auto t2 = array2.mutable_unchecked<4>(); // Mandate 4 dims
  auto t3 = array3.mutable_unchecked<4>(); // Mandate 4 dims

#pragma omp parallel for collapse(4)
  for (py::ssize_t i = 0; i < t3.shape(0); i++) {
    for (py::ssize_t j = 0; j < t3.shape(1); j++) {
      for (py::ssize_t a = 0; a < t3.shape(2); a++) {
        for (py::ssize_t b = 0; b < t3.shape(3); b++) {
          for (py::ssize_t k = 0; k < t1.shape(2); k++) {
            for (py::ssize_t l = 0; l < t1.shape(3); l++) {
              t3(i, j, a, b) += t1(i, j, k, l) * t2(k, l, a, b);
            }
          }
        }
      }
    }
  }
}

PYBIND11_MODULE(pybind11_numpy, m) {
  m.doc() = "Example NumPy/C++ Interface"; // optional module docstring
  m.def("change_vector", &change_vector,
        "Updates the first element of a NumPy array.", py::arg().noconvert());
  m.def("change_4D_tensor", &change_4D_tensor,
        "Updates the first element of a NumPy 4D tensor.",
        py::arg().noconvert());
  m.def("contract_4D_tensors", &contract_4D_tensors,
        "Contract 2 4D tensors equivalent to t3 = "
        "np.einsum('ijkl,klab->ijab',t1,t2)",
        py::arg().noconvert(), py::arg().noconvert(), py::arg().noconvert());
}