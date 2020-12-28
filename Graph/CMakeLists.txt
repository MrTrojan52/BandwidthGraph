set(TARGET graph)
set(JSON_BuildTests OFF CACHE INTERNAL "")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

file(GLOB_RECURSE GRAPHLIB_SRCS src/*.cpp)

add_library(${TARGET} STATIC ${GRAPHLIB_SRCS})
target_include_directories(${TARGET} PUBLIC include)
target_include_directories(${TARGET} PUBLIC thirdparty)