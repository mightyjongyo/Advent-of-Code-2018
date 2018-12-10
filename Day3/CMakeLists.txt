project("day3")

set(SW_SRCS "day3.cpp" "claim.cpp")

set(CMAKE_CXX_FLAGS "-std=c++14")

add_executable(${PROJECT_NAME} ${SW_SRCS})
