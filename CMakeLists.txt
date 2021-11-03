cmake_minimum_required(VERSION 3.17)
project(FaustCPPConverter)
set(CMAKE_CXX_STANDARD 17)

include(CMake/FindDependencies.cmake)

add_subdirectory(Faust)
add_subdirectory(Apps)



