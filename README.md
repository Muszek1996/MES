# MES

Finite element method (FEM, Polish "MES") exercise in C++17 for 2D heat transfer. It builds a rectangular grid of 4-node elements from `dane.txt`, then computes the shape functions, Jacobian and conductivity matrix H for one element using 2-point Gauss integration (conductivity k = 30). Intermediate matrices are printed to the console.

- `dane.txt`: input (`H`, `L` grid size, `nH`, `nL` node counts, `t0` initial temperature)
- `DataStructures/`: `Node`, `Element`, `Grid`
- `Jacobian/`: shape functions, Jacobian, H matrix
- `Utils/ReadFile.h`: reads `key=value` input

## Build & run
```bash
cmake -B build && cmake --build build
cd build && ./MES     # reads ../dane.txt
```
