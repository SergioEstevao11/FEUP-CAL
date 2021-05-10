cmake_minimum_required(VERSION 3.17)
project(VaccineRouter)

set(CMAKE_CXX_STANDARD 14)

add_executable(VaccineRouter main.cpp Graph/Node.h Graph/Edge.h Graph/Graph.h Graph/Edge.cpp Graph/Node.cpp)