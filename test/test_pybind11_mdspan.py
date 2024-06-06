import numpy as np
from pybind11_mdspan import scale_tensor_3d

npt = np.testing


def test_scale_tensor_3d():
    N = 1000
    factor = 1.9876

    tensor = np.random.rand(N, N, N)
    tensor_copy = tensor.copy()
    scale_tensor_3d(tensor, factor)
    npt.assert_almost_equal(tensor, tensor_copy * factor)
