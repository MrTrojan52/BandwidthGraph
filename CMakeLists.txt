cmake_minimum_required(VERSION 3.17)
project(BandwidthGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

set(SOURCES main.cpp)

set(HEADERS)

add_subdirectory(Graph)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} graph)