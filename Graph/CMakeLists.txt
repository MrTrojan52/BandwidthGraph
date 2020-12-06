set(TARGET graph)
set(JSON_BuildTests OFF CACHE INTERNAL "")

file(GLOB_RECURSE GRAPHLIB_SRCS src/*.cpp)

add_library(${TARGET} STATIC ${GRAPHLIB_SRCS})
target_include_directories(${TARGET} PUBLIC include)
target_include_directories(${TARGET} PUBLIC thirdparty)