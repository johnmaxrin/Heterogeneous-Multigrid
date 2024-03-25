# Heterogeneous Multigrid Solver for Linear Systems: Implementation and Optimization using CSR Representation
This project aims to implement a heterogeneous multigrid solver for solving systems of linear equations represented using Compressed Sparse Row (CSR) format. The primary objective is to develop a robust and efficient solver capable of handling large and sparse matrices commonly encountered in various scientific and engineering applications. 

**Multigrid Algorithm Implementation:** The core of the project will focus on implementing the multigrid algorithm. This will include the design and implementation of interpolation and restriction operators to transfer information between different grid levels efficiently.

**Sparse Matrix Representation:** Matrices will be represented in the CSR format to optimize memory usage and computational efficiency, especially for large sparse matrices. The project will involve developing algorithms for matrix-vector multiplication and other necessary operations specific to the CSR format.

**Heterogeneous Computing:** To leverage the computational power of modern hardware, the implementation will explore heterogeneous computing techniques, utilizing both Distributed (MPI) and Shared Memory(OpenMP) effectively. This will involve parallelizing key parts of the algorithm to exploit the capabilities of different hardware architectures.


