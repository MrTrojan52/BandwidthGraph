cmake_minimum_required(VERSION 3.17)
project(BandwidthGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFT_CONGIG_DISABLE_WCHAR")
message(STATUS "Checking OpenMP")
find_package(OpenMP)
IF(OPENMP_FOUND)
    # add flags for OpenMP
    message(STATUS "Found OpenMP")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_SHARED_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
ELSE()
    message(FATAL_ERROR  "Missed OpenMP!")
ENDIF()
message(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
message(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
message(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(FORT_LIB_PATH "./third_party/fort")

set(SOURCES main.cpp)

set(HEADERS)

add_subdirectory(Graph)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

include_directories(${FORT_LIB_PATH})
add_library(fort_lib STATIC ${FORT_LIB_PATH}/fort.c)

target_link_libraries(${PROJECT_NAME} graph fort_lib)