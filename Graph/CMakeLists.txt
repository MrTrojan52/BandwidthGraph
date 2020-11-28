set(TARGET graph)

file(GLOB_RECURSE GRAPHLIB_SRCS src/*.cpp)

add_library(${TARGET} STATIC ${GRAPHLIB_SRCS})
target_include_directories(${TARGET} PUBLIC include)