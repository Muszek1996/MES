cmake_minimum_required(VERSION 3.12)
project(MES)

set(CMAKE_CXX_STANDARD 17)

add_executable(MES main.cpp DataStructures/Node/Node.cpp DataStructures/Node/Node.h DataStructures/Element/Element.cpp DataStructures/Element/Element.h DataStructures/Grid/Grid.cpp DataStructures/Grid/Grid.h Utils/ReadFile.h)