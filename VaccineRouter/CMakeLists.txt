cmake_minimum_required(VERSION 3.17)
project(VaccineRouter)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)

add_executable(VaccineRouter main.cpp graph/Node.h graph/Edge.h graph/Graph.h graph/Edge.cpp graph/Node.cpp graph/Graph.cpp graph/GraphReader.cpp graph/GraphReader.h algorithms/Dijkstra.cpp algorithms/Dijkstra.h algorithms/BiDijkstra.cpp algorithms/BiDijkstra.h algorithms/Kosaraju.cpp algorithms/Kosaraju.h algorithms/Tarjan.cpp algorithms/Tarjan.h algorithms/AStar.cpp algorithms/AStar.h algorithms/ClarkeWright.cpp algorithms/ClarkeWright.h GraphDisplayer.cpp GraphDisplayer.h structures/Route.cpp structures/Route.h structures/POI.cpp structures/POI.h MenuInterface.cpp MenuInterface.h Manager.cpp Manager.h)

target_link_libraries(VaccineRouter graphviewer)