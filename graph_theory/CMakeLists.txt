cmake_minimum_required(VERSION 3.24)
project(graph_theory)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        graph_theory
#        output_matrix_table.cpp
        "adiacent matrix.cpp"
)
