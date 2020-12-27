cmake_minimum_required(VERSION 3.17)
project(BandwidthGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -DFT_CONGIG_DISABLE_WCHAR")
set(FORT_LIB_PATH "./third_party/fort")

set(SOURCES main.cpp)

set(HEADERS)

add_subdirectory(Graph)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

include_directories(${FORT_LIB_PATH})
add_library(fort_lib STATIC ${FORT_LIB_PATH}/fort.c)

target_link_libraries(${PROJECT_NAME} graph fort_lib)