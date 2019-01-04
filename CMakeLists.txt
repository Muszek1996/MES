cmake_minimum_required(VERSION 3.12)
project(MES)

set(CMAKE_CXX_STANDARD 17)

add_executable(MES main.cpp Jacobian/Jacobian.cpp Jacobian/Jacobian.h DataStructures/Node/Node.cpp DataStructures/Node/Node.h DataStructures/Element/Element.cpp DataStructures/Element/Element.h DataStructures/Grid/Grid.cpp DataStructures/Grid/Grid.h Utils/ReadFile.h ShapeFunctions/shapeF.cpp ShapeFunctions/shapeF.h Jacobian/Derivatives/Derivatives.cpp Jacobian/Derivatives/Derivatives.h Jacobian/JacobiMatrix/J.cpp Jacobian/JacobiMatrix/J.h HMatrix/HMatrix.cpp HMatrix/HMatrix.h Utils/MatrixInitializer.h CMatrix/MatrixC.cpp CMatrix/MatrixC.h BoundaryConditions/BoundC.cpp BoundaryConditions/BoundC.h VectorP/VectorP.cpp VectorP/VectorP.h)