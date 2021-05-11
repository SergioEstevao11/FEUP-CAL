cmake_minimum_required(VERSION 3.17)
project(VaccineRouter)

set(CMAKE_CXX_STANDARD 14)

add_executable(VaccineRouter main.cpp graph/Node.h graph/Edge.h graph/Graph.h graph/Edge.cpp graph/Node.cpp graph/Graph.cpp graph/GraphReader.cpp graph/GraphReader.h algorithms/Dijkstra.cpp algorithms/Dijkstra.h algorithms/BiDijkstra.cpp algorithms/BiDijkstra.h algorithms/Kosaraju.cpp algorithms/Kosaraju.h algorithms/Tarjan.cpp algorithms/Tarjan.h algorithms/AStar.cpp algorithms/AStar.h algorithms/BiAStar.cpp algorithms/BiAStar.h)