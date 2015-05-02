cmake_minimum_required(VERSION 3.2)
project(SpaceSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BASE "${CMAKE_SOURCE_DIR}/src")
set(IO_DIR ${BASE}/io)
set(PHYS_DIR ${BASE}/phycics)
set(APP_DIR ${BASE}/sim)

add_subdirectory(${IO_DIR})
add_subdirectory(${PHYS_DIR})

include_directories(${IO_DIR})
include_directories({PHYS_DIR})
include_directories(${APP_DIR})

FILE(GLOB SRCS src/sim/*.cpp
              src/sim/*.h)

add_executable(SpaceSim ${SRCS})

target_link_libraries(SpaceSim libio libphys)