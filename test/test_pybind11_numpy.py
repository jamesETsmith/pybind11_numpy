import numpy as np
from pybind11_numpy import change_vector
from pybind11_numpy import change_4D_tensor
from pybind11_numpy import contract_4D_tensors

npt = np.testing

def test_change_vector():
    N = 100

    v = np.random.rand(N)
    v_copy = v.copy()
    change_vector(v)
    npt.assert_almost_equal(v[0] - v_copy[0], 1)

def test_change_tensor():
    N = 20

    tensor = np.random.rand(N, N, N, N)
    tensor_copy = tensor.copy()
    change_4D_tensor(tensor)
    npt.assert_almost_equal(tensor[0, 0, 0, 0] - tensor_copy[0, 0, 0, 0], 1)



def test_contract_tensors():
    N = 20

    t1 = np.random.rand(N, N, N, N)
    t2 = np.random.rand(N, N, N, N)
    t3_copy = np.einsum('ijkl,klab->ijab', t1, t2)

    t3 = np.zeros_like(t3_copy)
    contract_4D_tensors(t1, t2, t3)
    npt.assert_array_almost_equal(t3, t3_copy)
