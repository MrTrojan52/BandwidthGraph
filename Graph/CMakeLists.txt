set(TARGET graph)
set(JSON_BuildTests OFF CACHE INTERNAL "")

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

file(GLOB_RECURSE GRAPHLIB_SRCS src/*.cpp)

add_library(${TARGET} STATIC ${GRAPHLIB_SRCS})
target_include_directories(${TARGET} PUBLIC include)
target_include_directories(${TARGET} PUBLIC thirdparty)